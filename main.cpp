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
        {"����",0,100},
        {"С��",1,100},
        {"���¸�",2,100},
        {"��ǫ",0,100},
        {"����",1,100}
    };

char levels[][20] = {"����","����","�ʹ���","�ʺ�"};
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
        cout << "��" << day << "��" << endl;
        cout << "1����ּѡ��\n" << "2����������\n" << "3�������乬\n" << "4���ټ�����" << endl;
        cout << "�������ּ��";
        if(!(cin >> choice))
        {
            cin.clear();
            cin.ignore();
            cout << "ֻ��ѡ�����֣�����" << endl;
            system("pause");
            continue;
        }
        else
        {
            switch(choice)
            {
            case 1:
                //����
                if(count >= 6)
                {
                    cout << "������Ϊ���ˣ�����ע�����尡��" << endl;
                    system("pause");
                    continue;
                }
                else
                {
                    cout << "������ּѡ���ˣ�" << endl;
                    cout << "�������������:";
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
                //����
                cout << "����Ҫ������λ���";
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
                    cout << "���в��޴��˰���" << endl;
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
                //ɾ��
                cout << "Ҫ�����乬�����������ǣ�";
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
                    cout << "�龪һ��������Ҫ�����乬��" << endl;
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
                    cout << "��������øжȼ�10" << endl;
                    for(i=0;i<count;i++)
                        girls[i].loves += 10;
                    print(count);
                    dying(count,day);
                }
                break;
            case 4:
                //����
                cout << "����Ҫ�ټ���λ����:";
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
                    cout << "���в��޴��ˣ������ǲ��ǼǴ��ˣ�" << endl;
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
                cout << "����Ϸ�ԣ��������ذ���" << endl;
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
    cout << left << setw(10) << "����" << setw(10) << "����" << "����" << endl;
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
        cout << "���ѵ������ǣ�ȥ���ǵ���ˢ��������" << endl;
        cout << "������ҹ��ս���ʵ��䣬��ִ��" << b << "�졣�òҰ�������" << endl;
        exit(0);
    }
}
