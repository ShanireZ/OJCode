#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream fin("family.in");
ofstream fout("family.out");
struct Cow
{
    string name;   /*姓名*/
    int idMom = 0; /*母亲id*/
};

int main()
{
    int n;
    fin >> n;
    string A, B;
    fin >> A >> B;
    string rel[n][2];
    string names[n * 2];
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        fin >> rel[i][0] >> rel[i][1]; /*姓名存储 母0  女1*/
        names[pos++] = rel[i][0];
        names[pos++] = rel[i][1];
    }

    sort(names, names + 2 * n); /*统计一共多少牛*/
    int sum = 1;
    for (int i = 1; i < 2 * n; i++)
    {
        if (names[i] == names[i - 1])
        {
            continue;
        }
        sum++;
    }

    Cow cows[sum + 1]; /*分配节点姓名*/
    cows[1].name = names[0];
    pos = 1;
    for (int i = 2; i <= sum; i++)
    {
        for (int j = pos; j < 2 * n; j++)
        {
            if (names[j] == names[j - 1])
            {
                continue;
            }
            cows[i].name = names[j];
            pos = j + 1;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int mom, dau;
        for (int j = 1; j <= sum; j++) /*找到母女对应的id*/
        {
            if (cows[j].name == rel[i][0])
            {
                mom = j;
            }
            if (cows[j].name == rel[i][1])
            {
                dau = j;
            }
        }
        cows[dau].idMom = mom; /*定位id链*/
    }

    int idA, idB; /*A的id B的id*/
    for (int i = 1; i <= sum; i++)
    {
        if (A == cows[i].name)
        {
            idA = i;
        }
        if (B == cows[i].name)
        {
            idB = i;
        }
    }

    int relA[sum], relB[sum]; /*记录A与B链条*/
    memset(relA, 0, sizeof(relA));
    memset(relB, 0, sizeof(relB));
    relA[0] = idA;
    int posA = 1;
    int id = cows[idA].idMom;
    while (id != 0)
    {
        relA[posA++] = id;
        id = cows[id].idMom;
    }
    relB[0] = idB;
    int posB = 1;
    id = cows[idB].idMom;
    while (id != 0)
    {
        relB[posB++] = id;
        id = cows[id].idMom;
    }

    int trig = 1; /*判断是否相交*/
    for (int i = 0; relA[i] != 0; i++)
    {
        for (int j = 0; relB[j] != 0; j++)
        {
            if (relA[i] == relB[j])
            {
                int temp = min(i, j); /*如果关系较远*/
                if (temp > 1)
                {
                    fout << "COUSINS";
                    return 0;
                }
                posA = i; /*相交处离A距离*/
                posB = j; /*相交处离B距离*/
                trig = 0;
                goto StopPos;
            }
        }
    }

StopPos:
    if (trig)
    {
        fout << "NOT RELATED";
        return 0;
    }

    int lvMaster, lvServant;
    int idMaster, idServant;
    if (posA == posB)
    {
        fout << "SIBLINGS";
        return 0;
    }
    else if (posA > posB)
    {
        lvMaster = posB;
        lvServant = posA;
        idMaster = idB;
        idServant = idA;
    }
    else
    {
        lvMaster = posA;
        lvServant = posB;
        idMaster = idA;
        idServant = idB;
    }
    int lvGap = lvServant - lvMaster;
    if (lvMaster == 0)
    {
        fout << cows[idMaster].name << " is the ";
        while (lvGap > 2)
        {
            fout << "great-";
            lvGap--;
        }
        if (lvGap == 2)
        {
            fout << "grand-";
        }
        fout << "mother of " << cows[idServant].name;
    }
    else
    {
        fout << cows[idMaster].name << " is the ";
        while (lvGap > 1)
        {
            fout << "great-";
            lvGap--;
        }
        fout << "aunt of " << cows[idServant].name;
    }

    return 0;
}