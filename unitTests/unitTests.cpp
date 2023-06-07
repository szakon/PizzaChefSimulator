#include <gtest/gtest.h>

TEST() {}

TEST(TestAnalyseXML, TestGroup) {
    std::string s = R"(<?xml version = "1.0"?>
                       <Group label="testGroup" x="0" y="1">
                           <Circle label="testCircle1" x="2" y="3" r="4" color="Black"/>
                           <Circle label="testCircle2" x="5" y="6" r="7" color="Black"/>
                       </Group>)";
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(s.c_str());
    ASSERT_TRUE(result) << result.description(); // Si jamais result est faux, indique que le test est faux *et* affiche la string result.description() (qui contient la raison de l'erreur)
    Group g{ doc.child("Group") };
    std::string g_dump_ref =
R"(Group "testGroup", x: 0, y: 1, children: [
| Circle "testCircle1", x: 2, y: 3, r: 4, color: "Black"
| Circle "testCircle2", x: 5, y: 6, r: 7, color: "Black"
]
)";
    EXPECT_EQ(g.dump(""), g_dump_ref);
}
