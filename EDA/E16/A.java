// classe base
public class A {
    protected char atribA;
    protected int igual; // atributo de mesmo nome nas 3 classes da hierarquia
    
    public A(char o, int i){
        this.atribA = o;
        this.igual = i;
        System.out.println("Construtor de A para o objeto: " + this.atribA);
    }
	public void mostrarAtributos(){
        System.out.println("atribA: " + atribA);
        System.out.println("Igual de A: " + igual);
    }
}
