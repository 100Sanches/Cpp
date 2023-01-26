#include <bits/stdc++.h>
using namespace std;

// Função para achar o próximo menor elemento
vector<int> proximomenorelemento(vector<int>& arr,int n){
	stack<int> st;

	// Para os elementos que não possuem o próximo elemento menor será -1
	st.push(-1);

	// Armazena índices na saída
	vector<int> direita(n);

	// Comece do ultimo índice
	for (int i = n - 1; i >= 0; i--) {

		// Se o elemento superior estiver classificado, não há necessidade de fazer nada, apenas armazene a resposta e coloque o elemento atual na pilha
		if ((st.top() != -1)
			&& arr[st.top()] < arr[i]) {
			direita[i] = st.top();
			st.push(i);
		}
		else {
			while ((st.top() != -1)
				&& arr[st.top()]
						>= arr[i]) {
				st.pop();
			}
			direita[i] = st.top();
			st.push(i);
		}
	}
	return direita;
}

// Função para encontrar o elemento menor anterior
vector<int> menorelementoanterior(vector<int>& arr,int n){
	stack<int> st;
	st.push(-1);
	vector<int> esquerda(n);

	// Comece do primeiro índice
	for (int i = 0; i < n; i++) {
		if ((st.top() != -1)
			&& arr[st.top()] < arr[i]) {
			esquerda[i] = st.top();
			st.push(i);
		}
		else {
			while ((st.top() != -1)
				&& arr[st.top()]
						>= arr[i]) {
				st.pop();
			}
			esquerda[i] = st.top();
			st.push(i);
		}
	}
	return esquerda;
}

// Função para obter a área máxima considerando cada linha como a base do histograma
int pegarMaxArea(vector<int>& arr, int n){

	vector<int> direita(n);
	direita = proximomenorelemento(arr, n);
    // Encontra o menor elemento que o elemento atual no lado direito

	vector<int> esquerda(n);
	esquerda = menorelementoanterior(arr, n);
    // Encontra o menor elemento que o elemento atual no lado esquerdo

	int maxarea = INT_MIN;

	// Agora os vetores esquerdo e direito têm índice do menor elemento em esquerda e direita respectivamente, portanto a diferença de direita - esquerda - 1 nos dará largura e, portanto, área = altura(curr==arr[i]) * largura;
	for (int i = 0; i < n; i++) {
		int altura = arr[i];
		if (direita[i] == -1) {
			direita[i] = n;
		}
		int largura = direita[i] - esquerda[i] - 1;
		maxarea = max(maxarea,altura * largura);
	}
	return maxarea;
}

// Função para calcular o maximo da area do retangulo
int maxAreaRetangulo(vector<vector<int> >& M,int n, int m){

	// Calcule a área máxima para a primeira linha
	int area = pegarMaxArea(M[0], m);
	int maxarea = area;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (M[i][j] != 0) {
				// Adiciona as alturas das linhas anteriores na atual
				M[i][j] = M[i][j]
						+ M[i - 1][j];
			}
			else {
				// Se a altura atual for 0, não adicione alturas anteriores
				M[i][j] = 0;
			}
		}
		maxarea = max(maxarea,pegarMaxArea(M[i], m));
	}
	return maxarea;
}

// Código principal que chama as funções
int main(){
	int N = 4, M = 5;
	vector<vector<int> > amt = {
		{ 1, 0, 1, 0, 0 },
		{ 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 1, 0 },
	};

	cout << maxAreaRetangulo(amt, N, M);
	return 0;
}
