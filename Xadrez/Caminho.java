package xadrez;

public class Caminho {
    
    private Tabuleiro tabuleiro;
    private String jogada;
    
    public Caminho(String jogada, Tabuleiro tab){
        tabuleiro = tab;
        this.jogada = jogada;
    }

    public boolean estaLivre(){
        int linhaInicial = jogada.charAt(0)-48;
        int colunaInicial = jogada.charAt(1)-96;
        int linhaFinal = jogada.charAt(2) - 48;
        int colunaFinal = jogada.charAt(3) - 96;
        
        String peca = tabuleiro.getPeca(linhaInicial, colunaInicial);
        
        
        //SE FOR CAVALO IGNORA
        if("Cp".equals(peca) || "Cb".equals(peca)){
            return true;
        }
        
        //PERCORRE CAMINHO E VERIFICA
        while(linhaFinal != linhaInicial || colunaFinal != colunaInicial){

            if(linhaFinal > linhaInicial) linhaInicial++;
            else if(linhaFinal < linhaInicial) linhaInicial--;
            
            if(colunaFinal > colunaInicial) colunaInicial++;
            else if(colunaFinal < colunaInicial) colunaInicial--;
        

            if((linhaFinal != linhaInicial || colunaFinal != colunaInicial) && tabuleiro.getPeca(linhaInicial, colunaInicial) != null){
                return false;
            }
            
            
        }
        
        return true;
        
    }
    
    
    public String casaInicial(){  
        return "" + jogada.charAt(0) + jogada.charAt(1);
    }
    
    public String casaFinal(){
        return "" + jogada.charAt(2) + jogada.charAt(3);
    }
    
    
}
