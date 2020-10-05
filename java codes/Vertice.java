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
 * Classe responsável por implementar os Vertices do Grafo utilizado no sistema.
 *
 * @author Roberto Maia
 * @author Daniel Dourado
 */
import java.util.ArrayList;

public class Vertice implements Comparable<Vertice> {

    private String nome;
    private int distancia = 0;
    private Vertice pai;
    private ArrayList<Aresta> incidentes = new ArrayList<Aresta>();
    private ArrayList<Vertice> vizinhos = new ArrayList<Vertice>();
    private boolean visitado = false;
    /**
     * Metodo responsavel por alterar o nome do vertice
     * @param nome 
     */
    public Vertice(String nome) {
        this.setNome(nome);
    }
    /**
     * Metodo responsavel por retornar o nome do vertice
     * @return Nome do vertice
     */
    public String getNome() {
        return nome;
    }
    /**
     * Metodo responsavel por alterar o nome do vertice
     * @param nome 
     */
    public void setNome(String nome) {
        this.nome = nome;
    }
    /**
     * Metodo responsavel por retonar a distancia do vertice
     * @return Distancia do vertice
     */
    public int getDistancia() {
        return distancia;
    }
    /**
     * Metodo responsavel por alterar a distancia do vertice
     * @param distancia 
     */
    public void setDistancia(int distancia) {
        this.distancia = distancia;
    }
    /**
     * Metodo responsavel por retornar o vertice "pai" do vertice
     * @return  Vertice "Pai" do vertice
     */
    public Vertice getPai() {
        return pai;
    }
    /**
     * Metodo responsavel por alterar o vertice "pai" do vertice
     * @param pai Novo vertice "pai"
     */
    public void setPai(Vertice pai) {
        this.pai = pai;
    }
    /**
     * Metodo responsavel por dizer se o vertice ja foi visitado 
     * @return true se ja foi visitado e false caso nao tenha sido
     */
    public boolean isVisitado() {
        return visitado;
    }
    /**
     * Metodo responsavel por verificar e possivelmente
     * alterar o estado "isVisitado" do vertice
     * @param visitado 
     */
    public void setVisitado(boolean visitado) {
        this.visitado = visitado;
    }
    /**
     * Metodo responsavel por retonar a lista de arestas incidentes do vertice
     * @return Lista de arestas
     */
    public ArrayList<Aresta> getIncidentes() {
        return incidentes;
    }
    /**
     * Metodo responsavel por adicionar aresta incidente ao grafo
     * @param incide 
     */
    public void addIncidentes(Aresta incide) {
        this.incidentes.add(incide);

        //adicionando vizinhos a lista
        if ((incide.getOrigem().getNome().equals(this.getNome()))
                && (!this.isVizinho(incide.getDestino()))) {

            this.addVizinhos(incide.getDestino());

        } else if ((incide.getDestino().getNome().equals(this.getNome()))
                && (!this.isVizinho(incide.getOrigem()))) {

            this.addVizinhos(incide.getOrigem());
        }
    }
    /**
     * Metodo responsavel por adcionar um vertice "vizinho" ao vertice
     * @param vizinho Vertice "vizinho"
     */
    public void addVizinhos(Vertice vizinho) {
        this.vizinhos.add(vizinho);
    }
    /**
     * Metodo responsavel por retonar a lista de vertices "vizinhos"
     * @return Lista de vertices "vizinhos"
     */
    public ArrayList<Vertice> getVizinhos() {
        return vizinhos;
    }
    /**
     * Metodo responsavel por verificar se um dado vertice e vizinho ou nao
     * @param vizinho Vertice que sera comparado
     * @return ture se for vizinho e false caso nao seja
     */
    public boolean isVizinho(Vertice vizinho) {
        int i;

        for (i = 0; i < this.vizinhos.size(); i++) {
            if (this.vizinhos.get(i).getNome().equals(vizinho.getNome())) {
                return true;
            }
        }

        return false;
    }
    /**
     * Metodo responsavel por comparar vertices com base em suas distancias
     * @param vertice Vertice que sera comparado
     * @return -1 caso o vertice do parametro estiver mais longe, 0 se estiveram
     *  na mesma distancia e +1 se o vertice da classe estiver mais longe
     */
    @Override
    public int compareTo(Vertice vertice) {

        if (this.getDistancia() < vertice.getDistancia()) {
            return -1;
        } else if (this.getDistancia() == vertice.getDistancia()) {
            return 0;
        }

        return 1;
    }

    @Override
    public String toString() {
        String s = " ";
        s += this.getNome();
        return s;
    }

}
