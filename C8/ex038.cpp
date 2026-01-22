#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Variáveis globais para serem acessíveis na DFS
int H, W;
vector<string> mapa;
vector<vector<bool>> visitado;

// Arrays auxiliares para mover nas 4 direções (Cima, Baixo, Esq, Dir)
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// Estrutura para ajudar na ordenação final
struct Lingua {
    char letra;
    int contador;
};

// Função de Flood Fill (usando DFS)
// O objetivo é marcar todos os vizinhos da mesma letra como visitados
void floodFill(int r, int c, char letraAlvo) {
    
    if (r < 0 || r >= H || c < 0 || c >= W) return;
    
   
    if (visitado[r][c] || mapa[r][c] != letraAlvo) return;

   
    visitado[r][c] = true;

    for (int i = 0; i < 4; i++) {
        floodFill(r + dr[i], c + dc[i], letraAlvo);
    }
}

// Função de comparação para o sort
bool comparar(const Lingua &a, const Lingua &b) {
    
    if (a.contador != b.contador) {
        return a.contador > b.contador;
    }
    
    return a.letra < b.letra;
}

void resolver(int numCaso) {
    cin >> H >> W;
    
    
    mapa.resize(H);
    visitado.assign(H, vector<bool>(W, false));
    for (int i = 0; i < H; i++) {
        cin >> mapa[i];
    }

    // Mapa para contar quantos 'estados' cada letra tem
    map<char, int> contagens;

    // Percorrer cada célula da matriz
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            
            if (!visitado[i][j]) {
                char letraAtual = mapa[i][j];
                
                // Incremento o contador dessa língua
                contagens[letraAtual]++;
                
                // Disparo o flood fill para "pintar" toda a região conectada
                floodFill(i, j, letraAtual);
            }
        }
    }

    // Passar os dados do map para um vetor para poder ordenar
    vector<Lingua> resultados;
    for (auto const& [key, val] : contagens) {
        resultados.push_back({key, val});
    }

    sort(resultados.begin(), resultados.end(), comparar);
    cout << "World #" << numCaso << endl;
    for (const auto &res : resultados) {
        cout << res.letra << ": " << res.contador << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        resolver(i);
    }

    return 0;
}