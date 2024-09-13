package xadrez;

public class Casa {
    
    private String cor;
    private int linha, coluna;
    private Peca pecaCasa;

    public Casa( int linha, int coluna, String cor){
        this.coluna = coluna;
        this.cor = cor;
        this.linha = linha;
        pecaCasa = null;
    }

    public String getPeca(){
        if(this.pecaCasa != null)
            return pecaCasa.desenho();
        
        return null;
    }

    public void setPecaCasa(Peca p){
        pecaCasa = p;
    }
    
    public Peca getPecaCasa(){
        return pecaCasa;
    }

    public int getLinha(){
        return linha;
    }

    public int getColuna(){
        return coluna;
    }

    public String getCor(){
        return cor;
    }

    public void setPecaCasa(String tipo, String cor){

        if (tipo.equals("Cavalo")) {
            this.pecaCasa = new Cavalo(cor);
        }
        else if(tipo.equals("Torre")){
            this.pecaCasa = new Torre(cor);
        }
        else if(tipo.equals("Peao")){
            this.pecaCasa = new Peao(cor);
        }
        else if(tipo.equals("Rei")){
            this.pecaCasa = new Rei(cor);
        }
        else if(tipo.equals("Bispo"))
        {
            this.pecaCasa = new Bispo(cor);
        }
        else if (tipo.equals("Rainha")) {
            this.pecaCasa = new Dama(cor);
        }
    }
}
