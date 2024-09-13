package xadrez;

import java.util.Scanner;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.FileReader;

public class Gerenciador {
    
    public static void main(String[] args) {
        
        int escolha = 0;
        Scanner sc = new Scanner(System.in);
        String nomeArquivo;
    
        do {
            imprimirMenu();
            
            try {

                escolha = sc.nextInt();
                sc.nextLine();
                
                switch (escolha) {
                    case 1:
                        System.out.print("Digite o nome do jogador 1:");
                        String nome1 = sc.nextLine();
                        System.out.print("Digite o nome do jogador 2:");
                        String nome2 = sc.nextLine();

                        Jogo novoJogo = new Jogo(nome1, nome2);
                        novoJogo.jogar(sc);

                        System.out.printf("Digite o nome do arquivo para salvar o jogo: ");
                        nomeArquivo = sc.nextLine();
                        System.out.println("nomeArquivo:" + nomeArquivo);

                        try{
                            salvar(novoJogo, nomeArquivo);
                        } catch(IOException e){
                            System.out.println("Erro ao ler o arquivo: " + e.getMessage());
                        }

                        break;
                    
                    case 2:
                        System.out.println("Digite o nome do arquivo:");
                        nomeArquivo = sc.nextLine();

                        try(BufferedReader reader = new BufferedReader(new FileReader(nomeArquivo))){
                            Jogo carregaJogo = new Jogo(reader.readLine(), reader.readLine());
                            String linha;

                            while((linha = reader.readLine()) != null){
                                carregaJogo.carregar(linha);
                            }
                            carregaJogo.jogar(sc);
                            salvar(carregaJogo, nomeArquivo);
                        } catch(IOException e){
                            System.out.println("Erro ao ler o arquivo: " + e.getMessage());
                        }


                        break;

                    case 3:
                        


                        break;

                    default:
                        System.out.println("Digite uma opção válida");
                }
            } 
            catch (InputMismatchException e) {
                System.out.println("Digite um número!");
                sc.nextLine();
            }

        } while (escolha != 3);

        
        
    }

    public static void imprimirMenu(){
        System.out.println("Bem vindo ao jogo de xadrez!");
        System.out.println("1 - iniciar um jogo novo");
        System.out.println("2 - carregar um jogo interrompido");
        System.out.println("3 - sair");
        System.out.print("Escolha uma opcao: ");
    }


    public static void salvar(Jogo jogo, String nomeArquivo) throws IOException{
            BufferedWriter writer = new BufferedWriter(new FileWriter(nomeArquivo));
            String nome1 = jogo.getNomePlayer1();
            String nome2 = jogo.getNomePlayer2();
            
            writer.append(nome1);
            writer.append('\n');
            writer.append(nome2);
            writer.append('\n');
            writer.append(jogo.getJogadas());
            writer.close();
    }

}
