// B é derivada de A e base para C
public class B extends A {
    protected char atribB;
    protected int igual; // atributo de mesmo nome nas 3 classes da hierarquia
    
    public B(char o, int i){
        super('a', 1);
        this.atribB = o;
        this.igual = i;
        System.out.println("Construtor de B para o objeto: " + this.atribB);
    }
        @Override
	public void mostrarAtributos(){
        super.mostrarAtributos();
        System.out.println("atribB: " + this.atribB);
        System.out.println("Igual de B: " + this.igual);
    }
}
