package xadrez;

public abstract class Peca {

    protected String cor;

    public Peca(String color){
        this.cor = color;
    }

    public abstract String desenho();
    
    public abstract boolean movimentoValido(int linhaO, int linhaD, int colunaO, int colunaD);

    public abstract String caminho(int linhaO, int linhaD, int colunaO, int colunaD);
}
