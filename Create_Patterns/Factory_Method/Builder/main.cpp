#include "Builder.hpp"

int main(int argc , const char *argv[])
{
    //建造亡灵怪物的建造者和指挥官
    UndeadMonsterBuilder* undead_builder = new UndeadMonsterBuilder(); 
    MonsterCommander undead_commander(undead_builder);

    //构建亡灵类怪物
    Monster* undead_monster = undead_commander.Construct("1253679201245");

    
    //构建元素和机械怪物同理
    MechineMonsterBuilder* mechine_builder = new MechineMonsterBuilder();
    MonsterCommander mechine_commander(mechine_builder);

    Monster* mechine_monster = mechine_commander.Construct("1253679201245");
    
    
    ElementMonsterBuilder* element_builder = new ElementMonsterBuilder();
    MonsterCommander element_commander(element_builder);

    Monster* element_monster = element_commander.Construct("1253679201245");


    delete undead_builder;
    delete mechine_builder;
    delete element_builder;
    delete undead_monster;
    delete mechine_monster;
    delete element_monster;

    return 0;
}