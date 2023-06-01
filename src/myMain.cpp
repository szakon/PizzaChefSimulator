#include <iostream>
#include <map>
#include "myMain.h"
#include "Drawing.h"
#include "colors.h"

using namespace std;

void process_clone(Shape *obj_to_modify, Drawing &d, map<string, Shape*, std::less<>> & string2shape)
{
    std::string label;
    map<string, Shape*, std::less<>>:: iterator it;
    cout << endl;
    do {
        cout << "=> Label of clone?" << endl;
        cin >> label;
        it = string2shape.find(label);
        if (it != string2shape.end()) {
            cout << "*** Error: Label '" << label << "' already exists in the Drawing. Please give an unused label. ***" << endl;
        }
    } while (it != string2shape.end());
    auto clone = obj_to_modify->clone();
    clone->set_label(label);
    d.add(std::move(clone));
}

void process_change_color(Shape *obj_to_modify) {
    string color;
    vector<string>::iterator colorIndex;
    cout << endl;
    do {
        cout << "Choose new color among : ";
        for (auto const &c: colors_as_string) {
            cout << c << " ";
        }
        cout << endl;
        cout << "===> Which color?" << endl;
        cin >> color;
        colorIndex = std::find(colors_as_string.begin(),colors_as_string.end(), color);
        if (colorIndex == colors_as_string.end()) {
            cout << "*** Error: Color '" << color << "' is not an available color. ***" << endl;
        }
    } while (colorIndex == colors_as_string.end());
    obj_to_modify->set_color(color);
}

void process_translation(Shape *obj_to_modify) {
    int delta_x;
    cout << endl << "===> delta_x?" << endl;
    cin >> delta_x;
    int delta_y;
    cout << "===> delta_y?" << endl;
    cin >> delta_y;
    obj_to_modify->translation(delta_x, delta_y);
}

int myMain()
{
    pugi::xml_document doc;
    if (auto result = doc.load_file("resources/visage.xml"); !result)
    {
        std::cerr << "Could not open file visage.xml because " << result.description() << std::endl;
        return 1;
    }

    Drawing d{ doc.child("Drawing") };

    SFML_output out;

    do {
        out.clean();
        d.draw(out);
        out.display();

        map<string, Shape*, std::less<>> string2shape;
        d.populate(string2shape);
        cout << endl << d.dump("");

        cout << "=> Label of object to modify (or SAVE to save in save.xml file or EXIT to exit)?" << endl;
        std::string label;
        cin >> label;
        if (label == "EXIT"sv)
            break;
        if (label == "SAVE") {
            cout << "TODO SAVE function to be implemented" << endl;
            continue;
        }
        map<string, Shape*, std::less<>>:: iterator it;
        it = string2shape.find(label);
        if (it == string2shape.end()) {
            cout << "*** Error: Could not find label '" << label << "' ***" << endl;
            continue;
        }
        Shape *obj_to_modify = it->second;

        cout << endl << R"(1 : Change color
2 : Copy
3 : Translation by (delta_x, delta_y)
)";
        cout << "==> Num function to invoke?" << endl;
        int num_func;
        cin >> num_func;

        switch (num_func)
        {
            case 1:
                process_change_color(obj_to_modify);
                break;
            case 2:
                process_clone(obj_to_modify, d, string2shape);
                break;
            case 3:
                process_translation(obj_to_modify);
                break;
            default:
                cout << endl << "*** Error : Unknown number ***" << endl;
        }
        cout << endl;
    } while(!out.check_user_closes_window());

    return 0;
}
