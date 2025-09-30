# NOTEBOOK DE PROGRAMAÇÃO COMPETITIVA - ESTRUTURAS DE DADOS

**Foco: TEP/Estrutura_de_dados**

## ÍNDICE

1. [Vetores](#vetores)
2. [Listas](#listas)
3. [Pilhas e Filas](#pilhas-e-filas)
4. [Árvores Binárias](#árvores-binárias)
5. [Árvores m-árias](#árvores-m-árias)
6. [Hashes](#hashes)
7. [Técnicas Importantes](#técnicas-importantes)

---

## VETORES

### Fundamentos

**Complexidade:**
- Acesso: O(1)
- Inserção no final: O(1) amortizado
- Inserção no meio: O(n)
- Remoção no final: O(1)
- Remoção no meio: O(n)
- Busca: O(n) ou O(log n) se ordenado

**Uso:** Estrutura básica para armazenar elementos sequenciais.

### Exemplo Rápido

```cpp
vector<int> v = {1, 2, 3, 4, 5};
v.push_back(6);           // [1,2,3,4,5,6]
v.pop_back();             // [1,2,3,4,5]
v.insert(v.begin() + 2, 10); // [1,2,10,3,4,5]
v.erase(v.begin() + 2);   // [1,2,3,4,5]
sort(v.begin(), v.end()); // ordena
```

### Exemplo Completo: Two Pointers

```cpp
vector<int> arr = {1, 3, 5, 7, 9};
int target = 12;
int left = 0, right = arr.size() - 1;

while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target) {
        cout << "Par encontrado: " << arr[left] << ", " << arr[right] << endl;
        break;
    } else if (sum < target) {
        left++;
    } else {
        right--;
    }
}
```

### Exemplo Completo: Prefix Sum

```cpp
vector<int> nums = {1, 2, 3, 4, 5};
vector<int> prefix(nums.size() + 1, 0);
for (int i = 0; i < nums.size(); i++) {
    prefix[i + 1] = prefix[i] + nums[i];
}
// Soma do intervalo [l, r]: prefix[r+1] - prefix[l]
```

### Problemas

**OJ 11093 - Just Finish it Up**

Verificar se existe alguma posição inicial em um circuito circular onde um carro consegue completar toda a volta. Use uma varredura linear mantendo o saldo de combustível acumulado. Se em algum ponto o saldo fica negativo, a posição inicial deve estar depois desse ponto crítico.

**CF 137B - Permutation**

Encontrar a menor permutação que falta em uma sequência de 1 a n. Use um set ou vetor booleano para marcar os números presentes, depois encontre o primeiro número ausente. A resposta é a quantidade de números que faltam.

---

## LISTAS

### Listas Encadeadas Simples

**Complexidade:**
- Acesso: O(n)
- Inserção no início: O(1)
- Inserção no final: O(n) ou O(1) com ponteiro para cauda
- Remoção no início: O(1)
- Remoção arbitrária: O(n)

**Uso:** Quando há muitas inserções/remoções no início.

### Implementação

```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insertFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertBack(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }

    void remove(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != val) {
            curr = curr->next;
        }
        if (curr->next) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
};
```

### Lista Duplamente Encadeada

```cpp
struct DNode {
    int data;
    DNode *prev, *next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    DNode *head, *tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertFront(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertBack(int val) {
        DNode* newNode = new DNode(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
};
```

### Lista Circular

```cpp
class CircularList {
public:
    Node* head;

    CircularList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* curr = head;
            while (curr->next != head) curr = curr->next;
            curr->next = newNode;
            newNode->next = head;
        }
    }
};
```

---

## PILHAS E FILAS

### Pilhas (Stack)

**Complexidade:** Todas operações O(1)
- push: inserir no topo
- pop: remover do topo
- top: acessar o topo

**Uso:** LIFO (Last In First Out) - parênteses, backtracking, DFS

### Exemplo Rápido

```cpp
stack<int> s;
s.push(1);
s.push(2);
s.push(3);
cout << s.top() << endl; // 3
s.pop();
cout << s.top() << endl; // 2
```

### Exemplo Completo: Verificar Parênteses Balanceados

```cpp
bool verificaParenteses(string s) {
    stack<char> st;
    map<char, char> pares = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty() || st.top() != pares[c]) return false;
            st.pop();
        }
    }
    return st.empty();
}
```

### Problemas

**CF 612C - Replace To Make Regular Bracket Sequence**

Usar pilha para verificar se uma sequência de diferentes tipos de parênteses pode ser transformada em uma sequência regular. Conte quantas substituições são necessárias quando os tipos não correspondem. Se a estrutura básica não for válida (quantidade ímpar ou ordem errada), é impossível.

**OJ 11111 - Generalized Matrioshkas**

Usar pilha para verificar se bonecas russas (matrioshkas) estão aninhadas corretamente. Valores negativos indicam abertura, positivos indicam fechamento. Verifique se cada boneca interna cabe dentro da externa e se as capacidades são respeitadas acumulando os tamanhos das bonecas internas.

### Pilhas Monótonas

**Complexidade:** O(n) para processar n elementos (cada elemento entra e sai uma vez)

**Uso:** Encontrar próximo maior/menor elemento, calcular áreas máximas

### Implementação: Próximo Menor à Esquerda

```cpp
vector<int> nextSmallerLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> s; // pilha monotônica crescente

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        result[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return result;
}
```

### Implementação: Maior Retângulo em Histograma

```cpp
long long maxRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    long long maxArea = 0;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            int h = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, (long long)h * width);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int h = heights[s.top()];
        s.pop();
        int width = s.empty() ? n : n - s.top() - 1;
        maxArea = max(maxArea, (long long)h * width);
    }

    return maxArea;
}
```

### Problemas

**CSES 1645 - Nearest Smaller Values**

Para cada posição, encontrar o elemento mais próximo à esquerda que seja menor. Use pilha monotônica crescente: ao processar cada elemento, remova da pilha todos os elementos maiores ou iguais, pois eles nunca serão resposta para elementos futuros.

**AGC 005B - Minimum Sum**

Use pilha monotônica para determinar, para cada elemento, até onde ele é mínimo à esquerda e direita. Cada elemento contribui com seu valor multiplicado pelo tamanho do intervalo onde é mínimo.

**CF 547B - Mike and Feet**

Para cada tamanho de grupo k, encontrar a força máxima (mínimo no grupo). Use pilha monotônica para encontrar, para cada elemento, quantas posições à esquerda e direita ele é o mínimo. Isso determina o maior grupo onde ele é o mínimo, e você pode usar suffix maximum para preencher respostas de grupos menores.

### Filas (Queue)

**Complexidade:** Todas operações O(1)
- push: inserir no final
- pop: remover do início
- front: acessar o primeiro

**Uso:** FIFO (First In First Out) - BFS, simulações

### Exemplo Rápido

```cpp
queue<int> q;
q.push(1);
q.push(2);
q.push(3);
cout << q.front() << endl; // 1
q.pop();
cout << q.front() << endl; // 2
```

### Exemplo Completo: BFS

```cpp
void bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```

### Problemas

**OJ 10935 - Throwing Cards Away I**

Simular o processo de jogar fora a carta do topo e mover a próxima para o final até sobrar uma carta. Use uma fila para simular esse processo: remova o primeiro (jogue fora), remova o próximo e insira no final (move para baixo).

**LC 933 - Number of Recent Calls**

Manter uma janela deslizante dos últimos 3000ms. Use uma fila para armazenar timestamps e remova elementos antigos (mais de 3000ms atrás) sempre que adicionar um novo timestamp. O tamanho da fila é a resposta.

### Filas Monótonas (Deque)

**Complexidade:** O(n) amortizado para processar n elementos

**Uso:** Sliding window maximum/minimum, otimizar DP

### Implementação: Máximo em Janela Deslizante

```cpp
vector<int> slidingWindowMaximum(vector<int>& nums, int k) {
    deque<int> dq; // armazena índices
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove elementos fora da janela
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Mantém deque decrescente
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}
```

### Problemas

**CSES 3221 - Sliding Window Minimum**

Encontrar o mínimo em cada janela de tamanho k. Use deque monotônico crescente para manter candidatos. Remove elementos fora da janela e elementos maiores que o atual (nunca serão mínimos futuros).

**Leetcode 84 - Largest Rectangle in Histogram**

Encontrar o maior retângulo em um histograma. Use pilha monotônica crescente para determinar, para cada barra, quantas barras consecutivas à esquerda e direita têm altura maior ou igual. A área é altura × largura total.

**CF 846D - Monitor**

Problema de janela deslizante 2D. Use filas monótonas de forma aninhada: primeiro processe linhas para obter min/max em cada janela horizontal, depois processe colunas sobre esses resultados.

---

## ÁRVORES BINÁRIAS

### Árvore Binária de Busca (BST)

**Propriedade:** Para cada nó, todos os valores à esquerda são menores, todos à direita são maiores.

**Complexidade (árvore balanceada):**
- Busca: O(log n)
- Inserção: O(log n)
- Remoção: O(log n)
- Travessia: O(n)

**Complexidade (pior caso - desbalanceada):** O(n)

### Implementação

```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    // Inserção
    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    // Busca
    bool search(TreeNode* node, int val) {
        if (!node) return false;
        if (node->val == val) return true;
        if (val < node->val) return search(node->left, val);
        return search(node->right, val);
    }

    // Encontrar mínimo
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    // Remoção
    TreeNode* remove(TreeNode* node, int val) {
        if (!node) return nullptr;

        if (val < node->val) {
            node->left = remove(node->left, val);
        } else if (val > node->val) {
            node->right = remove(node->right, val);
        } else {
            // Nó encontrado
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Dois filhos: substitui pelo sucessor
            TreeNode* temp = findMin(node->right);
            node->val = temp->val;
            node->right = remove(node->right, temp->val);
        }
        return node;
    }
};
```

### Travessias

```cpp
// Inorder (Esq-Raiz-Dir) - ordem crescente em BST
void inorder(TreeNode* node, vector<int>& result) {
    if (!node) return;
    inorder(node->left, result);
    result.push_back(node->val);
    inorder(node->right, result);
}

// Preorder (Raiz-Esq-Dir)
void preorder(TreeNode* node, vector<int>& result) {
    if (!node) return;
    result.push_back(node->val);
    preorder(node->left, result);
    preorder(node->right, result);
}

// Postorder (Esq-Dir-Raiz)
void postorder(TreeNode* node, vector<int>& result) {
    if (!node) return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->val);
}

// BFS (por nível)
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}
```

### Problemas

**BEE 1195 - Árvore Binária de Busca**

Implementar inserção em BST e realizar travessias inorder, preorder e postorder. Siga as definições: preorder (raiz-esq-dir), inorder (esq-raiz-dir), postorder (esq-dir-raiz).

**BEE 1466 - Percurso em Árvore por Nível**

Realizar BFS (travessia por nível) em uma BST. Use fila para processar nós nível por nível, da esquerda para direita.

**BEE 1191 - Recuperação de Árvore**

Reconstruir árvore binária a partir de travessias preorder e inorder. O primeiro elemento do preorder é sempre a raiz. Encontre-o no inorder para dividir subárvores esquerda e direita, então resolva recursivamente.

**OJ 10077 - The Stern-Brocot Number System**

Navegar na árvore de Stern-Brocot para encontrar fração. A árvore tem propriedades de BST: vá para esquerda se target < atual, direita se target > atual. A fração mediana entre dois nós é (p1+p2)/(q1+q2).

### BST na STL (set, map)

**Implementação:** Red-Black Tree (balanceada automaticamente)

**Complexidade:** Todas operações O(log n)

### Set

```cpp
set<int> s;
s.insert(5);
s.insert(2);
s.insert(8);
s.insert(2); // não insere duplicata

// Busca
if (s.find(5) != s.end()) {
    cout << "Encontrado\n";
}

// Lower bound: primeiro >= x
auto it1 = s.lower_bound(3); // aponta para 5

// Upper bound: primeiro > x
auto it2 = s.upper_bound(5); // aponta para 8

// Remover
s.erase(2);

// Iterar (ordem crescente)
for (int x : s) cout << x << " ";
```

### Map

```cpp
map<string, int> m;
m["alice"] = 10;
m["bob"] = 20;
m["charlie"] = 15;

// Acesso
cout << m["alice"] << endl;

// Verificar existência
if (m.count("bob")) {
    cout << "Bob existe\n";
}

// Iterar (ordem lexicográfica)
for (auto [key, val] : m) {
    cout << key << ": " << val << endl;
}
```

### Multiset

```cpp
multiset<int> ms;
ms.insert(5);
ms.insert(2);
ms.insert(5); // permite duplicatas
ms.insert(8);

// Contar ocorrências
cout << ms.count(5) << endl; // 2

// Remover uma ocorrência
ms.erase(ms.find(5)); // remove apenas uma

// Remover todas
ms.erase(5); // remove todas as ocorrências
```

### Problemas

**BEE 1897 - Jogo Esperto**

BFS com estados visitados armazenados em set. Cada estado representa um número alcançável. Use set para evitar revisitar estados e fila para BFS entre transformações possíveis.

**OJ 12049 - Just Prune The List**

Encontrar quantos elementos devem ser removidos de duas listas para torná-las iguais. Use multiset ou map para contar frequências. Para cada elemento, a diferença absoluta de frequências indica quantos devem ser removidos.

**ABC 110C - String Transformation**

Verificar se uma string pode ser transformada em outra via permutação de caracteres. Use map para criar mapeamentos e verificar consistência: cada caractere de s deve mapear para exatamente um caractere de t.

**CF 1004C - Sonya and Robots**

Contar quantos prefixos de um array contêm todos elementos distintos vistos até o momento. Use set para rastrear elementos únicos e verifique se cada prefixo mantém a propriedade de distinção.

### Heaps Binárias (Binary Heap)

**Propriedade:** Árvore binária completa onde cada nó é >= filhos (max-heap) ou <= filhos (min-heap)

**Complexidade:**
- Inserção: O(log n)
- Remoção do topo: O(log n)
- Acesso ao topo: O(1)
- Construção: O(n)

### Priority Queue

```cpp
// Max-heap (padrão)
priority_queue<int> maxHeap;
maxHeap.push(5);
maxHeap.push(2);
maxHeap.push(8);
cout << maxHeap.top() << endl; // 8
maxHeap.pop();

// Min-heap
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(5);
minHeap.push(2);
minHeap.push(8);
cout << minHeap.top() << endl; // 2
minHeap.pop();
```

### Exemplo Completo: K Maiores Elementos

```cpp
vector<int> kLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}
```

### Exemplo Completo: Mediana Dinâmica

```cpp
class MedianFinder {
    priority_queue<int> maxHeap; // metade inferior
    priority_queue<int, vector<int>, greater<int>> minHeap; // metade superior

public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
```

### Problemas

**Timus 1306 - Sequence Median**

Encontrar mediana em uma sequência que cresce dinamicamente. Use dois heaps: max-heap para metade inferior e min-heap para metade superior. Balance os tamanhos para que difiram no máximo por 1. A mediana está no topo do heap maior.

**CF 994B - Knights of a Polygonal Table**

Para cada cavaleiro com poder p e ouro g, ele pode derrotar até k cavaleiros mais fracos e pegar seu ouro. Ordene por poder, use heap para manter os k maiores valores de ouro disponíveis até o momento, e some para cada cavaleiro.

**Codechef RRATING - Restaurant Rating**

Processamento de queries de mediana em janela deslizante. Mantenha dois heaps balanceados e, ao remover elementos antigos, use lazy deletion (marcar como removido) ou reconstrua periodicamente.

---

## ÁRVORES M-ÁRIAS

### Union-Find Disjoint Sets (UFDS)

**Complexidade com union by rank e path compression:**
- Find: O(α(n)) ≈ O(1) amortizado
- Union: O(α(n)) ≈ O(1) amortizado

α(n) é a inversa da função de Ackermann (cresce muito lentamente)

**Uso:** Detectar componentes conexos, ciclos em grafos, MST (Kruskal)

### Implementação

```cpp
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find com path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by rank
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;

        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;

        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
```

### Exemplo Completo: Detectar Ciclo

```cpp
bool hasCycle(int n, vector<pair<int, int>>& edges) {
    DSU dsu(n);
    for (auto [u, v] : edges) {
        if (!dsu.unite(u, v)) {
            return true; // ciclo detectado
        }
    }
    return false;
}
```

### Problemas

**SPOJ HERDING - Herding**

Determinar quantos grupos de vacas existem em um campo onde cada vaca se move para uma direção fixa. Use DSU para unir vacas que eventualmente se encontram seguindo suas direções. O número de componentes conexos é a resposta.

**OJ 1197 - The Suspects**

Estudantes em contato com o suspeito zero podem estar infectados. Use DSU para unir todos os alunos que pertencem ao mesmo grupo/atividade. Após processar todos os grupos, o tamanho do componente conexo que contém o estudante 0 é a resposta.

### Fenwick Tree (Binary Indexed Tree)

**Complexidade:**
- Construção: O(n log n) ou O(n) otimizada
- Range Sum Query: O(log n)
- Point Update: O(log n)

**Uso:** Range queries com updates pontuais (soma, XOR, etc)

### Implementação: BIT 1D

```cpp
class BIT {
    vector<long long> tree;
    int n;

public:
    BIT(int size) : n(size) {
        tree.assign(n + 1, 0);
    }

    // Adiciona val na posição idx
    void update(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }

    // Soma do prefixo [1, idx]
    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }

    // Soma do intervalo [l, r]
    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};
```

### Implementação: BIT 2D

```cpp
class BIT2D {
    vector<vector<long long>> tree;
    int n, m;

public:
    BIT2D(int rows, int cols) : n(rows), m(cols) {
        tree.assign(n + 1, vector<long long>(m + 1, 0));
    }

    void update(int x, int y, long long val) {
        for (int i = x; i <= n; i += i & -i) {
            for (int j = y; j <= m; j += j & -j) {
                tree[i][j] += val;
            }
        }
    }

    long long query(int x, int y) {
        long long sum = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

    // Soma do retângulo [(x1,y1), (x2,y2)]
    long long rangeQuery(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2)
               - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};
```

### Problemas

**SPOJ FENTREE - Fenwick Trees**

Implementação direta de Fenwick Tree com operações de range sum query e point update. Construa a BIT e responda queries de soma em intervalos e atualizações pontuais usando as operações fundamentais da estrutura.

**OJ 12798 - Handball**

Contar quantos jogadores participaram de todos os jogos. Use BIT ou array simples para contar presenças. Para cada jogador, verifique se a soma de presenças é igual ao número total de jogos.

**OJ 12532 - Interval Product**

Determinar se o produto de um intervalo é positivo, negativo ou zero após múltiplos updates. Use BIT modificada para rastrear o sinal: armazene +1 para positivo, -1 para negativo, 0 para zero. O produto dos sinais no intervalo determina o resultado.

**SPOJ INVCNT - Inversion Count**

Contar pares (i,j) onde i<j e arr[i]>arr[j]. Use coordinate compression se necessário e BIT para contar, ao processar da direita para esquerda, quantos números menores já foram vistos. Cada número contribui com a contagem de menores à sua direita.

**CF 295A - Greg and Array**

Aplicar múltiplas operações de range update e depois responder range queries. Use BIT ou difference array para processar updates em batch, depois aplique todos de uma vez e responda queries com prefix sum ou BIT.

**POJ 1195 - Mobile Phones**

Implementar BIT 2D para range sum queries e point updates em matriz. Processe comandos de update (incrementar célula) e query (soma de retângulo) usando as operações da BIT 2D.

### Segment Tree (Árvore de Segmentos)

**Complexidade:**
- Construção: O(n)
- Range Query: O(log n)
- Point/Range Update: O(log n)

**Uso:** Range queries e updates (soma, min, max, GCD, etc). Mais versátil que BIT, suporta operações não-inversíveis.

### Implementação: Segment Tree Básica

```cpp
class SegTree {
    vector<long long> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void updatePoint(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updatePoint(2 * node, start, mid, idx, val);
            } else {
                updatePoint(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        long long p1 = queryRange(2 * node, start, mid, l, r);
        long long p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }

public:
    SegTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, long long val) {
        updatePoint(1, 0, n - 1, idx, val);
    }

    long long query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};
```

### Implementação: Segment Tree com Lazy Propagation

```cpp
class SegTreeLazy {
    vector<long long> tree, lazy;
    int n;

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, long long val) {
        push(node, start, end);
        if (start > r || end < l) return;

        if (l <= start && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);

        push(2 * node, start, mid);
        push(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return 0;
        push(node, start, end);

        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        long long p1 = queryRange(2 * node, start, mid, l, r);
        long long p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }

public:
    SegTreeLazy(int size) : n(size) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void update(int l, int r, long long val) {
        updateRange(1, 0, n - 1, l, r, val);
    }

    long long query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};
```

### Implementação: Range Minimum Query (RMQ)

```cpp
class SegTreeRMQ {
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int queryRange(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return INT_MAX;
        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        int p1 = queryRange(2 * node, start, mid, l, r);
        int p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
        return min(p1, p2);
    }

public:
    SegTreeRMQ(vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, INT_MAX);
        build(arr, 1, 0, n - 1);
    }

    int query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};
```

### Problemas

**CF 339D - Xenia and Bit Operations**

Árvore de segmentos onde cada nível alterna entre operações OR e XOR. Construa a árvore bottom-up aplicando OR e XOR alternadamente. Para updates, modifique a folha e propague mudanças até a raiz mantendo a alternância.

**SPOJ KGSS - Maximum Sum**

Para cada range query, retornar a soma dos dois maiores elementos. Use segment tree onde cada nó armazena o maior e o segundo maior elemento de seu intervalo. Ao combinar nós, atualize esses dois valores corretamente.

**LA 6139 - Interval Product**

Similar ao OJ 12532. Determine se o produto de um intervalo é positivo, negativo ou zero. Use segment tree onde cada nó armazena o sinal do produto de seu intervalo. Combine sinais multiplicando-os.

---

## HASHES

### Hash Tables (Tabelas Hash)

**Complexidade (média):**
- Inserção: O(1)
- Busca: O(1)
- Remoção: O(1)

**Complexidade (pior caso):** O(n) com colisões

**Uso:** Busca rápida, contagem de frequências, deduplicação

### Unordered Set

```cpp
unordered_set<int> s;
s.insert(5);
s.insert(2);
s.insert(8);

// Busca O(1) média
if (s.find(5) != s.end()) {
    cout << "Encontrado\n";
}

// Sem ordem garantida
for (int x : s) cout << x << " ";
```

### Unordered Map

```cpp
unordered_map<string, int> m;
m["alice"] = 10;
m["bob"] = 20;

// Acesso O(1) média
cout << m["alice"] << endl;

// Contar frequências
vector<int> arr = {1, 2, 3, 2, 1, 3, 1};
unordered_map<int, int> freq;
for (int x : arr) freq[x]++;
```

### Hash Customizado

```cpp
// Hash para pair
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

unordered_set<pair<int, int>, PairHash> s;
s.insert({1, 2});
s.insert({3, 4});
```

### Rolling Hash (String Hashing)

```cpp
class RollingHash {
    static const long long MOD = 1e9 + 7;
    static const long long BASE = 31;
    vector<long long> hash, pow;

public:
    RollingHash(string s) {
        int n = s.size();
        hash.resize(n + 1);
        pow.resize(n + 1);
        pow[0] = 1;

        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * BASE + s[i] - 'a' + 1) % MOD;
            pow[i + 1] = (pow[i] * BASE) % MOD;
        }
    }

    // Hash da substring [l, r]
    long long getHash(int l, int r) {
        long long h = (hash[r + 1] - hash[l] * pow[r - l + 1]) % MOD;
        return (h + MOD) % MOD;
    }
};
```

### Problemas

**CF 244A - Dividing Orange**

Distribuir números de 1 a n*k em n grupos de k elementos, onde alguns números já estão pré-atribuídos. Use hash set para marcar números já usados, depois preencha cada grupo com números disponíveis sequencialmente.

**BEE 1256 - Tabelas Hash**

Implementar tabela hash com encadeamento. Para cada chave, calcule o índice usando módulo do tamanho da tabela. Armazene colisões em listas encadeadas. Imprima a estrutura resultante.

**OJ 12504 - Updating the Dictionary**

Comparar dois dicionários (maps) e reportar chaves adicionadas, removidas e modificadas. Use dois maps para armazenar os dicionários e itere comparando as chaves e valores, classificando as diferenças em três categorias.

---

## TÉCNICAS IMPORTANTES

### 1. Two Pointers

Percorrer array com dois índices (início/fim ou ambos crescendo)

```cpp
// Encontrar par com soma target em array ordenado
bool twoSum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}
```

### 2. Sliding Window

Janela deslizante de tamanho fixo ou variável

```cpp
// Maior soma de subarray de tamanho k
int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    int windowSum = 0;

    // Primeira janela
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Deslizar janela
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}
```

### 3. Prefix Sum

Calcular somas de intervalos em O(1) após preprocessamento O(n)

```cpp
vector<int> nums = {1, 2, 3, 4, 5};
vector<int> prefix(nums.size() + 1, 0);

for (int i = 0; i < nums.size(); i++) {
    prefix[i + 1] = prefix[i] + nums[i];
}

// Soma do intervalo [l, r]
int rangeSum = prefix[r + 1] - prefix[l];
```

### 4. Prefix Sum 2D

```cpp
vector<vector<long long>> prefixSum2D(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<long long>> prefix(n + 1, vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j]
                         + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    return prefix;
}

// Soma do retângulo [(x1,y1), (x2,y2)]
// result = prefix[x2+1][y2+1] - prefix[x1][y2+1] - prefix[x2+1][y1] + prefix[x1][y1]
```

### 5. Coordinate Compression

Mapear valores grandes para índices menores

```cpp
vector<int> compress(vector<int>& arr) {
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    vector<int> compressed(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        compressed[i] = lower_bound(sorted.begin(), sorted.end(), arr[i])
                        - sorted.begin();
    }
    return compressed;
}
```

### 6. Difference Array (Range Update)

Range updates em O(1) com prefix sum no final

```cpp
class DifferenceArray {
    vector<long long> diff;
    int n;

public:
    DifferenceArray(int size) : n(size) {
        diff.assign(n + 1, 0);
    }

    void updateRange(int l, int r, long long val) {
        diff[l] += val;
        diff[r + 1] -= val;
    }

    vector<long long> build() {
        vector<long long> result(n);
        result[0] = diff[0];
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] + diff[i];
        }
        return result;
    }
};
```

### 7. Sparse Table (RMQ estático)

RMQ estático em O(1) query, O(n log n) construção

```cpp
class SparseTable {
    vector<vector<int>> st;
    vector<int> lg;
    int n;

public:
    SparseTable(vector<int>& arr) {
        n = arr.size();
        int maxLog = 32 - __builtin_clz(n);
        st.assign(maxLog, vector<int>(n));
        lg.resize(n + 1);

        // Preprocessar logaritmos
        lg[1] = 0;
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        // st[j][i] = min no intervalo [i, i + 2^j - 1]
        for (int i = 0; i < n; i++) {
            st[0][i] = arr[i];
        }

        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j-1))]);
            }
        }
    }

    int query(int l, int r) {
        int j = lg[r - l + 1];
        return min(st[j][l], st[j][r - (1 << j) + 1]);
    }
};
```

---

## TEMPLATE PRINCIPAL

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Seu código aqui

    return 0;
}
```

---

## DICAS FINAIS

1. **Sempre analise a complexidade antes de implementar**
2. Vetores e arrays: Prefira `vector<>` do C++ para flexibilidade
3. Use `int` para 10^9, `long long` para 10^18
4. Cuidado com overflow em multiplicações e somas acumuladas
5. Para MOD: sempre `(x % MOD + MOD) % MOD` para evitar negativos
6. Leia os limites do problema para escolher a estrutura adequada
7. BIT é mais rápida que SegTree mas menos versátil
8. Use hash quando ordem não importa, BST quando importa
9. Sempre teste casos extremos: n=1, todos iguais, ordenado, etc
10. Para debug: imprima estruturas intermediárias

---

## TABELA DE ESCOLHA RÁPIDA

| Operação | Estrutura Recomendada | Complexidade |
|----------|----------------------|--------------|
| Range Sum + Point Update | Fenwick Tree | O(log n) |
| Range Sum + Range Update | Segment Tree Lazy | O(log n) |
| Range Min/Max/GCD | Segment Tree | O(log n) |
| RMQ estático | Sparse Table | O(1) query |
| Busca rápida sem ordem | unordered_set/map | O(1) média |
| Busca com ordem | set/map | O(log n) |
| Min/Max dinâmico | priority_queue | O(log n) |
| Componentes conexos | Union-Find | O(α(n)) ≈ O(1) |
| String matching | Rolling Hash | O(n+m) |
| Sliding window min/max | Deque monotônico | O(n) |