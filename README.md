# LabirintoDFS
 
Para este problema, uma matriz quadrada e formada com espaços livres e alguns bloqueios,  

que devem ser escritos dentro da função "create" em Labirinto.cpp conforme os comentários. 

  

O algoritmo então utiliza uma forma de busca DFS, que significa busca por fundo primeiro, 

implementada por uma pilha de pairs <int,int> que contém as coordenadas dos espaços na 

matriz. Num protótipo do algoritmo, eu mesmo tentei implementar uma pilha dinâmica,  

porem o programa compilava, mas dava segmentation fault nos mallocs. Esse protótipo pode 

ser revisado em https://onlinegdb.com/-9ur3kPmd. 

  

Ao compilar o código, este pede como input o tamanho da matriz Labirinto, ja que a matriz 

e quadrada, o input servira tanto como o número de colunas quanto de linhas, e obviamente 

este deve ser um inteiro positivo. Uma função "create", que pode ter sido editada antes  

para modificar os bloqueios, então cria uma matriz de ints, colocando 0's nos espaços 

vazios e 1 nos bloqueios. Outra função chamada "mostra" lê e imprime a matriz, além de 

formata-la a um aspecto mais amigável que vários zeros e uns. Zeros aparecem como espaços 

vazios e uns como "x" para marcar bloqueios. Esta também troca -1 por "o", mas esse 

método só aparece no fim da compilação. 

  

Após imprimir a matriz original, o método "CaminhoDFS" tenta sair de [0,0] e chegar a [n-1,n-1] 

na matriz, este faz isso por meio de uma pilha de pairs <int,int> que empilha as coordenadas 

visitadas, e um laco de repetição while que dura até o caminho chegar a [n-1, n-1] que 

envia o local atual a uma função "Proximo". Esta função compara as coordenadas atuais do 

caminho e seus arredores, e devolve um pair com as coordenadas de qual caminho seguir pelo  

padrão dfs, que é prioridade para descer ao fundo a não ser que o caminho esteja bloqueado. 

Se todos os caminhos a partir das coordenadas atuais forem inviáveis, a função "Proximo" 

devolve {-1,-1}, que é um par de teste da função "CaminhoDFS". Se o CaminhoDFS receber  

um pair de "Proximo" viável, este empilha as novas coordenadas e marca a Matriz com -1, já 

se "Proximo" retornar {-1,-1}, "CaminhoDFS" desempilha as últimas coordenadas, retornando as 

coordenadas anteriores até encontrar um caminho viável. "CaminhoDFS" também calcula o numero 

de iterações necessárias para chegar a seu destino, mostrando esse número por meio de um cout  

após seu laco de repetição acabar. 

  

Por fim, a função "mostra" imprime a nova matriz com o caminho andado. 
