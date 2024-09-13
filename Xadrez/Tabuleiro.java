package xadrez;

public class Tabuleiro { 
    
    private Casa casas[][];
    
    public Tabuleiro(){
        this.casas = new Casa[8][8];
        
        //INICIALIZAR CASAS
        for (int i = 0; i < 8 ; i++) {
            for (int j = 0; j < 8; j++) {
                
                //DEFINIR COR DA CASA 
                String cor;
                if((i+1) % 2 == (j+1) % 2)
                    cor = "p"; // preta
                else
                    cor = "b"; // branca
                
                casas[i][j] = new Casa(i,j,cor);
            }
        }

        //DEFINIR PEÇAS
        
        //Peoes brancos
        for(int i = 0; i < 8; i++){
            casas[1][i].setPecaCasa("Peao", "Branco");
        }
        //Peoes pretos
        for(int i = 0; i < 8; i++){
            casas[6][i].setPecaCasa("Peao", "Preto");
        }
        
        //Restante das peças brancas
        casas[0][0].setPecaCasa("Torre", "Branco");
        casas[0][7].setPecaCasa("Torre", "Branco");
        
        casas[0][1].setPecaCasa("Cavalo", "Branco");
        casas[0][6].setPecaCasa("Cavalo", "Branco");

        casas[0][4].setPecaCasa("Rei", "Branco");
        casas[0][3].setPecaCasa("Rainha", "Branco"); 
        
        casas[0][5].setPecaCasa("Bispo", "Branco");
        casas[0][2].setPecaCasa("Bispo", "Branco");

        //Restante das peças pretas
        casas[7][0].setPecaCasa("Torre", "Preto");
        casas[7][7].setPecaCasa("Torre", "Preto");  
        
        casas[7][1].setPecaCasa("Cavalo", "Preto");
        casas[7][6].setPecaCasa("Cavalo", "Preto");

        casas[7][3].setPecaCasa("Rainha", "Preto"); 
        casas[7][4].setPecaCasa("Rei", "Preto");
        
        casas[7][2].setPecaCasa("Bispo", "Preto");
        casas[7][5].setPecaCasa("Bispo", "Preto");
    }

    public boolean noLimite(int linha, int coluna){
        return (linha >= 1 && linha < 9 && coluna >= 1 && coluna < 9);
    }

    public String desenho(){
        /**  
         * 8
         * 7
         * 6
         * 5
         * 4
         * 3 
         * 2 P  P  P  P  P  P  P  P 
         * 1
         *  a  b  c  d  e  f  g  h
         */
        String desenho = "";
        desenho += "   a  b  c  d  e  f  g  h\n";
        
        //for drupo carprado 
        for (int i = 7; i >= 0; i--) {
            desenho += "" + (i + 1) + " ";
            for (int j = 0; j < 8; j++) {
                if (casas[i][j].getPeca() != null) {
                    desenho += casas[i][j].getPeca();
                }
                else{
                    desenho += " *" ; //casas[i][j].getCor()
                }
                desenho += " ";
            }
            desenho += "\n";
        }
        return desenho;
    }
    
    public String getPeca(int linha, int coluna){
        return casas[linha-1][coluna-1].getPeca();
    }
    
    public Casa getCasa(int linha, int coluna){
        return casas[linha-1][coluna-1];
    }

    public void setPecaCasa(int linha, int coluna, Peca novaPeca){

        casas[linha-1][coluna-1].setPecaCasa(novaPeca);
    }

    public Peca getPecaCasa(int linha, int coluna){
        return casas[linha-1][coluna-1].getPecaCasa();
    }

    public String getCaminhoPeca(int linhaO, int linhaD, int colunaO, int colunaD){
        Peca peca = getPecaCasa(linhaO, colunaO);

        return peca.caminho(linhaO, linhaD, colunaO, colunaD);
    }
}
