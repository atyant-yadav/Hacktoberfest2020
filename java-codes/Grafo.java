/**
 * Componente Curricular: Módulo Integrado de Programação II
 * Autor: <Roberto Maia Rodrigues Junior e Daniel Cavalcante Dourado>
 * Data:  <07/02/2019>
 *
 * Declaro que este código foi elaborado por mim de forma individual e não
 * contém nenhum trecho de código de outro colega ou de outro autor, tais como
 * provindos de livros e apostilas, e páginas ou documentos eletrônicos da
 * Internet. Qualquer trecho de código de outra autoria que uma citação para o
 * não a minha está destacado com autor e a fonte do código, e estou ciente que
 * estes trechos não serão considerados para fins de avaliação. Alguns trechos
 * do código podem coincidir com de outros colegas pois estes foram discutidos
 * em sessões tutorias.
 */
package model;

/**
 * Classe contendo a implementacao do grafo
 *
 * @author Roberto Maia
 * @author Daniel Dourado
 */
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class Grafo {

    private ArrayList<Aresta> arestas = new ArrayList<Aresta>();
    private ArrayList<Vertice> vertices = new ArrayList<Vertice>();
    private boolean hasCycle = false;

    /**
     * Método responsável por "limpar" as arestas e vertices do grafo, alem de
     * alterar o o atributo "hasCycle" para falso
     */
    public void clearLists() {
        this.arestas.clear();
        this.vertices.clear();
        this.setHasCycle(false);
    }

    /**
     * Método responsável por dizer se ha ou nao ciclos dentro do grafo
     *
     * @return true, caso exista ciclo, e nao, caso nao tenha
     */
    public boolean isHasCycle() {
        return hasCycle;
    }

    /**
     * Método responsável por alterar o estado de "hasCycle"
     *
     * @param hasCycle Novo estado de "hasCycle"
     */
    public void setHasCycle(boolean hasCycle) {
        this.hasCycle = hasCycle;
    }

    /**
     * Método responsável por adicionar uma aresta no grafo
     *
     * @param peso peso da aresta
     * @param origem Vertice origem
     * @param destino Vertice destino
     */
    public void addAresta(int peso, String origem, String destino) {
        int i, j, k;

        //adiciona vertices e retorna posicao
        i = this.addVertice(origem);
        j = this.addVertice(destino);

        //adiciona aresta na lista
        Aresta a = new Aresta(peso,
                this.vertices.get(i),
                this.vertices.get(j));

        temCiclo(a);
        this.arestas.add(a);
        k = this.arestas.size();

        //adiciona aresta na lista de arestas incidentes em cada vertice
        this.vertices.get(i).addIncidentes(this.arestas.get(k - 1));
        this.vertices.get(j).addIncidentes(this.arestas.get(k - 1));
    }

    /**
     * Método responsável por alterar o conjunto de arestas do grafo
     *
     * @param arestas Lista encadeada contendo o novo conjunto de arestas do
     * grafo
     */
    public void setArestas(ArrayList<Aresta> arestas) {
        this.clearLists();

        for (int i = 0; i < arestas.size(); i++) {
            this.addAresta(arestas.get(i).getPeso(),
                    arestas.get(i).getOrigem().getNome(),
                    arestas.get(i).getDestino().getNome());
        }
    }

    /**
     * Método responsável por alterar o conjunto de vertices do grafo
     *
     * @param vertices Lista encadeada contendo o novo conjunto de vertices do
     * grafo
     */
    public void setVertices(ArrayList<Vertice> vertices) {
        this.clearLists();

        for (int i = 0; i < vertices.size(); i++) {

            //se ja existir na lista nao passara daqui
            if (this.posicaoVertice(vertices.get(i).getNome()) == this.vertices.size()) {
                //adicionando as arestas correspondentes a tais vertices
                for (int j = 0; j < vertices.get(i).getIncidentes().size(); j++) {

                    //se o adicionado for a origem desse seu incidente, e o seu destino estiver na lista de vertices
                    if ((vertices.get(i).getNome().equals(vertices.get(i).getIncidentes().get(j).getOrigem().getNome()))
                            && (this.posicaoVertice(vertices.get(i).getIncidentes().get(j).getDestino().getNome()) != this.vertices.size())) {

                        this.addAresta(vertices.get(i).getIncidentes().get(j).getPeso(),
                                vertices.get(i).getIncidentes().get(j).getOrigem().getNome(),
                                vertices.get(i).getIncidentes().get(j).getDestino().getNome());

                        //se o adicionado for o destino desse seu incidente, e o sua origem estiver na lista de vertices	
                    } else if ((vertices.get(i).getNome().equals(vertices.get(i).getIncidentes().get(j).getDestino().getNome()))
                            && (this.posicaoVertice(vertices.get(i).getIncidentes().get(j).getOrigem().getNome()) != this.vertices.size())) {

                        this.addAresta(vertices.get(i).getIncidentes().get(j).getPeso(),
                                vertices.get(i).getIncidentes().get(j).getOrigem().getNome(),
                                vertices.get(i).getIncidentes().get(j).getDestino().getNome());

                    }
                }
                this.addVertice(vertices.get(i).getNome());
            }
        }
    }

    /**
     * Método responsável por adicionar um vertice ao grafgo
     *
     * @param nome
     * @return
     */
    public int addVertice(String nome) {
        int i = this.posicaoVertice(nome);

        if (i == this.vertices.size()) {
            this.vertices.add(new Vertice(nome));
            return (this.vertices.size() - 1);
        }

        return i;
    }

    /**
     * Método responsável por eliminar os vertices "pai" de todos os vertices do
     * grafo
     */
    public void limparVerticesPai() {
        for (int i = 0; i < this.getVertices().size(); i++) {
            this.getVertices().get(i).setPai(null);
        }
    }

    /**
     * Método responsável por mudar o estado "visitado" de todos os vertices
     */
    public void limparVerticeVisitado() {
        for (int i = 0; i < this.getVertices().size(); i++) {
            this.getVertices().get(i).setVisitado(false);
        }
    }

    /**
     * Método responsável por mudar o estado "visitado" de todos as arestas
     */
    public void limparArestaVisitada() {
        for (int i = 0; i < this.getArestas().size(); i++) {
            this.getArestas().get(i).setVisitado(false);
        }
    }

    /**
     * Método responsável por gerar o arquivo de saida do programa
     *
     * @return
     */
    public double imprimeArvore() throws IOException {
        FileWriter fileWrite = new FileWriter("./Rotas Saida.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWrite);

        double pesoTotal = 0;

        for (int i = 0; i < arestas.size(); i++) {
            bufferedWriter.write(this.arestas.get(i).getOrigem().getNome() + "->" + this.arestas.get(i).getDestino().getNome() + " || " + " Distância: " + this.arestas.get(i).getPeso() + "KM");
            bufferedWriter.newLine();
            pesoTotal += this.arestas.get(i).getPeso();
        }

        bufferedWriter.close();
        return pesoTotal;
    }

    public double imprimeArvoreVolta() throws IOException {
        FileWriter fileWrite = new FileWriter("./Rotas Saida.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWrite);
        bufferedWriter.newLine();
        bufferedWriter.newLine();
        double pesoTotal = 0;
        //bufferedWriter.write("TRAJETORIA DE VOLTA :");
        for (int i = 0; i < arestas.size(); i++) {
            bufferedWriter.write(this.arestas.get(i).getDestino().getNome() + "->" + this.arestas.get(i).getOrigem().getNome() + " || " + " Distância: " + this.arestas.get(i).getPeso() + "KM");
            bufferedWriter.newLine();
            pesoTotal += this.arestas.get(i).getPeso();
        }
        //bufferedWriter.write("DISTANCIA TOTAL DE VOLTA :"+ pesoTotal);
        //System.out.println("");
        //fileWrite.close();
        bufferedWriter.close();
        return pesoTotal;
    }

    /**
     * Método responsável por retornar a lista encadeada de vertices do grafo
     *
     * @return Lista encadeada de vertices do grafo
     */
    public ArrayList<Vertice> getVertices() {
        return vertices;
    }

    /**
     * Método responsável por retornar a posicao que um vertice esta na lista
     * vertices
     *
     * @param nome Nome do vertice
     * @return a posicao do vertice
     */
    public int posicaoVertice(String nome) {
        int i;

        for (i = 0; i < this.vertices.size(); i++) {
            if (this.vertices.get(i).getNome().equals(nome)) {
                return i;
            }
        }

        //se nao encontrar retorna o tamanho da lista vertices
        return this.vertices.size();

    }

    /**
     * Método responsável por realizar uma pesquisa de vertice por nome e
     * retornar sua busca
     *
     * @param nome Nome para pesquisa
     * @return Vertice buscado
     */
    public Vertice acharVertice(String nome) {
        return this.vertices.get(this.posicaoVertice(nome));
    }

    /**
     * Método responsável por realizar uma pesquisa de aresta por meio dos
     * vertices que ela une
     *
     * @param vet1 Vertice origem
     * @param vet2 Vertice fim
     * @return A aresta buscada ou null caso ela nao seja encontrada
     */
    public Aresta acharAresta(Vertice vet1, Vertice vet2) {
        for (int i = 0; i < this.arestas.size(); i++) {
            if (((this.arestas.get(i).getOrigem().getNome().equals(vet1.getNome()))
                    && (this.arestas.get(i).getDestino().getNome().equals(vet2.getNome())))
                    || ((this.arestas.get(i).getOrigem().getNome().equals(vet2.getNome()))
                    && (this.arestas.get(i).getDestino().getNome().equals(vet1.getNome())))) {
                return this.arestas.get(i);
            }
        }
        return null;
    }

    /**
     * Método responsável por retornar a lista encadeada de arestas do grafo
     *
     * @return Lista de arestas
     */
    public ArrayList<Aresta> getArestas() {
        return arestas;
    }

    /**
     * Metodo que informa se ao adicionar certa aresta a arvore que vai receber
     * tera ciclo ou nao
     *
     * @param aresta Aresta que sera adicionada
     * @return true se ao adicionar a aresta um ciclo é criado e false caso nao
     * seja
     */
    public boolean temCiclo(Aresta aresta) {

        Vertice anterior = aresta.getDestino();

        for (int j = 0; j < this.getArestas().size(); j++) {

            for (int i = 0; i < this.getArestas().size(); i++) {

                if ((aresta == this.getArestas().get(i)) && (this.getArestas().get(i).isVisitado() == false)) {
                    this.getArestas().get(i).setVisitado(true);
                } else if (aresta != this.getArestas().get(i)) {

                    if (anterior.getNome().equals(this.getArestas().get(i).getOrigem().getNome())) {

                        if (aresta.getOrigem().getNome().equals(this.getArestas().get(i).getDestino().getNome())) {
                            this.limparArestaVisitada();
                            this.hasCycle = true;
                            return true;
                        } else {
                            anterior = this.getArestas().get(i).getDestino();
                            this.getArestas().get(i).setVisitado(true);
                        }

                    } else if (anterior.getNome().equals(this.getArestas().get(i).getDestino().getNome())) {

                        if (aresta.getOrigem().getNome().equals(this.getArestas().get(i).getOrigem().getNome())) {
                            this.limparArestaVisitada();
                            this.hasCycle = true;
                            return true;
                        } else {
                            anterior = this.getArestas().get(i).getOrigem();
                            this.getArestas().get(i).setVisitado(true);
                        }
                    }
                }
            }
        }
        this.limparArestaVisitada();
        this.hasCycle = false;
        return false;
    }

    /**
     * Metodo que retorna o caminho menos custoso entre dois vertices a partir
     * do algoritmo de Dijkstra
     *
     * @param v1 Vertice origem
     * @param v2 Vertice destino
     * @return Lista encadeada de Vertices que compoe o trajeto para ir da
     * origem ate o destino
     */
    public ArrayList<Vertice> encontrarMenorCaminhoDijkstra(Vertice v1, Vertice v2) {

        // Atributos usados na funcao encontrarMenorCaminho
        // Lista que guarda os vertices pertencentes ao menor caminho encontrado
        ArrayList<Vertice> menorCaminho = new ArrayList<Vertice>();

        // Variavel que recebe os vertices pertencentes ao menor caminho
        Vertice verticeCaminho;

        // Variavel que guarda o vertice que esta sendo visitado
        Vertice atual;

        // Variavel que marca o vizinho do vertice atualmente visitado
        Vertice vizinho;

        // Aresta que liga o atual ao seu vizinho;
        Aresta ligacao;

        // Lista dos vertices que ainda nao foram visitados
        ArrayList<Vertice> naoVisitados = new ArrayList<Vertice>();

        // Algoritmo de Dijkstra
        // Adiciona a origem na lista do menor caminho
        menorCaminho.add(v1);

        // Colocando a distancias iniciais 
        for (int i = 0; i < this.getVertices().size(); i++) {
            // Vertice atual tem distancia zero, e todos os outros,
            // 9999("infinita")
            if (this.getVertices().get(i).getNome().equals(v1.getNome())) {
                this.getVertices().get(i).setDistancia(0);
            } else {
                this.getVertices().get(i).setDistancia(9999);
            }
            // Insere o vertice na lista de vertices nao visitados
            naoVisitados.add(this.getVertices().get(i));
        }

        Collections.sort(naoVisitados);

        // O algoritmo continua ate que todos os vertices sejam visitados
        while (!naoVisitados.isEmpty()) {
            // Toma-se sempre o vertice com menor distancia, que eh o primeiro
            // da
            // lista

            atual = naoVisitados.get(0);
            /*
             * Para cada vizinho (cada aresta), calcula-se a sua possivel
             * distancia, somando a distancia do vertice atual com a da aresta
             * correspondente. Se essa distancia for menor que a distancia do
             * vizinho, esta eh atualizada.
             */
            for (int i = 0; i < atual.getVizinhos().size(); i++) {

                vizinho = atual.getVizinhos().get(i);

                if (!vizinho.isVisitado()) {

                    // Comparando a dist�ncia do vizinho com a poss�vel
                    // dist�ncia
                    ligacao = this.acharAresta(atual, vizinho);
                    if (vizinho.getDistancia() > (atual.getDistancia() + ligacao.getPeso())) {
                        vizinho.setDistancia(atual.getDistancia()
                                + ligacao.getPeso());
                        vizinho.setPai(atual);

                        /*
                         * Se o vizinho eh o vertice procurado, e foi feita uma
                         * mudanca na distancia, a lista com o menor caminho
                         * anterior eh apagada, pois existe um caminho menor
                         * vertices pais, ateh o vertice origem.
                         */
                        if (vizinho == v2) {
                            menorCaminho.clear();
                            verticeCaminho = vizinho;
                            menorCaminho.add(vizinho);
                            while (verticeCaminho.getPai() != null) {
                                menorCaminho.add(verticeCaminho.getPai());
                                verticeCaminho = verticeCaminho.getPai();

                            }
                            // Ordena a lista do menor caminho, para que ele
                            // seja exibido da origem ao destino.
                            Collections.sort(menorCaminho);

                        }
                    }
                }

            }
            // Marca o vertice atual como visitado e o retira da lista de nao
            // visitados
            atual.setVisitado(true);
            naoVisitados.remove(atual);
            /*
             * Ordena a lista, para que o vertice com menor distancia fique na
             * primeira posicao
             */

            Collections.sort(naoVisitados);

        }
        this.limparVerticesPai();
        return menorCaminho;
    }
}
