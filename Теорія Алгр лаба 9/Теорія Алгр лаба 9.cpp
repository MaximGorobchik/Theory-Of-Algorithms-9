#include <iostream> 
#include <cstring> 
using namespace std;

#define INF 9999999

//кількість вершин у графі
#define V 5

//створити двовимірний масив розміром 5x5
//для матриці суміжності для представлення графа

int G[V][V] = {
  { 0 , 9 , 75 , 0 , 0 },
  { 9 , 0 , 95 , 19 , 42 },
  { 75 , 95 , 0 , 51 , 66 },
  { 0 , 19 , 51 , 0 , 31 },
  { 0 , 42 , 66 , 31 , 0 }
};

int main() {

    int no_edge; //кількість ребрів            

    //створити масив для відстеження вибраної вершини
    //вибране стане істинним, інакше стане хибним
    int selected[V];

    //спочатку встановити вибране значення false
    memset(selected, false, sizeof(selected));

    //Встановіть кількість ребер на 0
    no_edge = 0;

    //кількість ребер у мінімальному остовному дереві буде
    //завжди менше (V -1), де V — кількість вершин у графі

    //виберіть 0-ту вершину та зробіть її істинною
    selected[0] = true;

    int x; //к-сть рядків           
    int y; //к-сть стовпців           

    //друк для ребра та ваги
    cout << "Edge" << ": " << "Weight";
    cout << endl;
    while (no_edge < V - 1) {

        //Для кожної вершини множини S знайдіть усі суміжні вершини
        //Визначте відстань від вершини, вибраної на кроці 1.
            //якщо вершина вже є в множині S, інакше її відкинути
            //виберіть іншу вершину близько до вибраної вершини на кроці 1.

            int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) { //    
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }

                    }
                }
            }
        }
        cout << x << " - " << y << " : " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }

    return 0;
}