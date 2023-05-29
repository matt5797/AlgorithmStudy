#include <iostream>
#include <vector>

using namespace std;

struct Tile
{
    int height;
    bool visited;
    bool water;
};

vector<pair<int, int>> dirs = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void DFS(Tile **tiles, int N, int water, int x, int y)
{
    int nx, ny;

    tiles[x][y].visited = true;
    for (pair<int, int> d : dirs)
    {
        nx = x+d.first;
        ny = y+d.second;
        if (nx >= 0 && nx <N && ny >= 0 && ny <N)
        {
            //cout << tiles[nx][ny].height << ' ';
            if (tiles[nx][ny].visited==false && tiles[nx][ny].water==false)
            {
                DFS(tiles, N, water, nx, ny);
            }
        }
    }
}

void printArr(Tile **tiles, int N)
{
    cout << "\n";
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            cout << "(" << tiles[i][j].height << "," << tiles[i][j].water << "," << tiles[i][j].visited << "), ";
        }
        cout << "\n";
    }
}

int main() {
    int N, max_height=0, count=0, pre_count, max_count=0;
    Tile **tiles;

    cin >> N;

    tiles = new Tile*[N];
    for (int i=0;i<N;i++)
    {
        tiles[i] = new Tile[N];
        for (int j=0;j<N;j++)
        {
            cin >> tiles[i][j].height;
            if (tiles[i][j].height>max_height)
                max_height = tiles[i][j].height;
        }
    }
    
    //printArr(tiles, N);

    for (int water=0; water<max_height; water++)
    {
        count = 0;

        for (int i=0;i<N;i++)
        {
            for (int j=0;j<N;j++)
            {
                tiles[i][j].visited = false;
                tiles[i][j].water = (tiles[i][j].height<=water) ? true : false;
            }
        }

        for (int i=0;i<N;i++)
        {
            for (int j=0;j<N;j++)
            {
                if (tiles[i][j].visited==false && tiles[i][j].water==false)
                {
                    DFS(tiles, N, water, i, j);
                    count++;
                }
            }
        }
        if (max_count < count)
            max_count = count;
        //cout << count << "\n";
        //printArr(tiles, N);
    }
    cout << max_count;

    return 0;
}