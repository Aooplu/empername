#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

void print(int a);
void dying(int a,int b);

struct Girls
{
    string name;
    int level;
    int loves;
};

Girls girls[6]={
        {"大乔",0,100},
        {"小乔",1,100},
        {"郭德纲",2,100},
        {"于谦",0,100},
        {"貂蝉",1,100}
    };

char levels[][20] = {"贵人","嫔妃","皇贵妃","皇后"};
int i;

int main()
{
    int demo = -1;
    int day = 1;
    string name1;
    int count = 5;
    int choice;
    print(count);
    while(day <= 10)
    {
        cout << "第" << day << "天" << endl;
        cout << "1、下旨选妃\n" << "2、临幸妃子\n" << "3、打入冷宫\n" << "4、召见妃子" << endl;
        cout << "请陛下下旨：";
        if(!(cin >> choice))
        {
            cin.clear();
            cin.ignore();
            cout << "只能选择数字！！！" << endl;
            system("pause");
            continue;
        }
        else
        {
            switch(choice)
            {
            case 1:
                //增加
                if(count >= 6)
                {
                    cout << "后宫人满为患了，皇上注意身体啊！" << endl;
                    system("pause");
                    continue;
                }
                else
                {
                    cout << "皇上下旨选妃了！" << endl;
                    cout << "新娘娘的名字是:";
                    cin >> name1;
                    girls[count].name = name1;
                    girls[count].level = 0;
                    girls[count].loves = 100;
                    for(i=0;i<count;i++)
                        girls[i].loves -= 10;
                    count++;
                    print(count);
                    dying(count,day);
                }
                break;
            case 2:
                //临幸
                cout << "皇上要临幸哪位娘娘：";
                cin >> name1;
                for(i=0;i<count;i++)
                {
                    if(name1 == girls[i].name)
                    {
                        demo = i;
                        break;
                    }
                }
                if(demo == -1)
                {
                    cout << "后宫中查无此人啊！" << endl;
                    system("pause");
                    continue;
                }
                else
                {
                    for(i=0;i<count;i++)
                    {
                        if(name1 == girls[i].name)
                        {
                            girls[i].loves += 20;
                            if(girls[i].level < 3)
                                girls[i].level++;
                        }
                        else
                            girls[i].loves -= 10;
                    }
                    print(count);
                    dying(count,day);
                }
                break;
            case 3:
                //删除
                cout << "要打入冷宫的娘娘名字是：";
                cin >> name1;
                for(i=0;i<count;i++)
                {
                    if(name1 == girls[i].name)
                    {
                        demo = i;
                        break;
                    }
                }
                if(demo == -1)
                {
                    cout << "虚惊一场，无人要打入冷宫。" << endl;
                    system("pause");
                    continue;
                }
                else
                {
                    for(i=demo;i<count;i++)
                    {
                        girls[i].name = girls[i+1].name;
                        girls[i].level = girls[i+1].level;
                        girls[i].loves = girls[i+1].loves;
                    }
                    count--;
                    cout << "所有娘娘好感度加10" << endl;
                    for(i=0;i<count;i++)
                        girls[i].loves += 10;
                    print(count);
                    dying(count,day);
                }
                break;
            case 4:
                //查找
                cout << "皇上要召见哪位娘娘:";
                cin >> name1;
                for(i=0;i<count;i++)
                {
                    if(name1 == girls[i].name);
                    {
                        demo = i;
                        break;
                    }
                }
                if(demo == -1)
                {
                    cout << "后宫中并无此人，皇上是不是记错了？" << endl;
                    system("pause");
                    continue;
                }
                else
                {
                    girls[demo].loves += 10;
                    for(i=0;i<count;i++)
                    {
                        if(i != demo) girls[i].loves -= 5;
                    }
                    print(count);
                    dying(count,day);
                }
                break;
            default:
                cout << "君无戏言，皇上慎重啊！" << endl;
                system("pause");
                continue;
                break;
            }
            day++;
        }
    }
    return 0;
}

void print(int a)
{
    for(i=0;i<25;i++)
        cout << "*";
    cout << endl;
    cout << left << setw(10) << "姓名" << setw(10) << "级别" << "爱意" << endl;
    for(i=0;i<25;i++)
        cout << "*";
    cout << endl;
    for(i=0;i<a;i++)
        cout << left << setw(10) << girls[i].name << setw(10) << levels[girls[i].level] << girls[i].loves << endl;
    for(i=0;i<25;i++)
        cout << "*";
    cout << endl;
}

void dying(int a,int b)
{
    int num = 0;
    for(i=0;i<a;i++) if(girls[i].loves < 60)
        num++;
    if(num >= 3)
    {
        cout << "觉醒的妃子们：去金銮殿上刷皇上啦！" << endl;
        cout << "经过几夜奋战，皇帝卒，共执政" << b << "天。好惨啊！！！" << endl;
        exit(0);
    }
}
