#pragma warning (disable: 4996)
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Box
{
private:
    long n;
    long m;
    long k;
    long l;
    long numOfBlocks = n * m * k;
public:

    Box(long a, long b, long c, long d)
    {
        n = a;
        m = b;
        c = k;
        l = d;
    }
    vector<long> cycle;
    long getName(long boxNumber)
    {
        long parent = cycle[boxNumber];
        if (parent >= 0)
        {
            boxNumber = getName(parent);
        }
        return boxNumber;
    }

    void mergeBoxes(long root1, long root2)
    {
        if (cycle[root1] < cycle[root2])
        {
            cycle[root1] += cycle[root2];
            cycle[root2] = root1;
        }
        else
        {
            cycle[root2] += cycle[root1];
            cycle[root1] = root2;
        }
    }

    void copyPath(long* from, long* to)
    {
        for (long i = 0; i < 3; ++i)
        {
            to[i] = from[i];
        }
    }

    long UniqueIndex(long* coordinates)
    {
        return (coordinates[0] * m * k + coordinates[1] * k + coordinates[2]);
    }

    void Solution(long* from, long* to, long& mainIndex, FILE* fout)
    {
        long currFrom[3], currTo[3];
        long root1, root2;

        copyPath(from, currFrom);
        copyPath(from, currTo);

        if (from[mainIndex] < to[mainIndex])
        {
            for (long i = from[mainIndex]; i < to[mainIndex]; ++i)
            {
                currFrom[mainIndex] = i;
                currTo[mainIndex] = i + 1;
                root1 = getName(UniqueIndex(currFrom));
                root2 = getName(UniqueIndex(currTo));
                if (root1 != root2)
                {
                    mergeBoxes(root1, root2);
                }
                else
                {
                    fprintf(fout, "%d %d %d ", currFrom[0] + 1, currFrom[1] + 1, currFrom[2] + 1);
                    fprintf(fout, "%d %d %d\n", currTo[0] + 1, currTo[1] + 1, currTo[2] + 1);
                }
            }
        }
        else
        {
            for (long i = from[mainIndex]; i > to[mainIndex]; --i)
            {
                currFrom[mainIndex] = i;
                currTo[mainIndex] = i - 1;
                root1 = getName(UniqueIndex(currFrom));
                root2 = getName(UniqueIndex(currTo));
                if (root1 != root2)
                {
                    mergeBoxes(root1, root2);
                }
                else
                {
                    fprintf(fout, "%d %d %d ", currFrom[0] + 1, currFrom[1] + 1, currFrom[2] + 1);
                    fprintf(fout, "%d %d %d\n", currTo[0] + 1, currTo[1] + 1, currTo[2] + 1);
                }
            }
        }
    }
};

int main()
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int n, m, k, l;
    fscanf(fin, "%d%d%d%d", &n, &m, &k, &l);
    Box box1(n, m, k, l);
    box1.cycle.reserve(n * m * k);
    box1.cycle.assign(n * m * k, -1);
    long from[3], to[3];
    long mainIndex = 0;

    for (long i = 0; i < l; ++i)
    {
        fscanf(fin, "%d%d%d", &from[0], &from[1], &from[2]);
        fscanf(fin, "%d%d%d", &to[0], &to[1], &to[2]);

        if (from[0] != to[0]) { mainIndex = 0; }
        else if (from[1] != to[1]) { mainIndex = 1; }
        else { mainIndex = 2; }
        for (long j = 0; j < 3; ++j)
        {
            from[j]--;
            to[j]--;
        }
        box1.Solution(from, to, mainIndex, fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}