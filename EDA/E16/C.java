// C é derivade de B que é derivada de A
public class C extends B {
    protected char atribC;
    protected int igual; // atributo de mesmo nome nas 3 classes da hierarquia
    
    public C(char o, int i){
        super('b', 2);
        this.atribC = o;
        this.igual = i;
        System.out.println("Construtor de C para o objeto: " + this.atribC);
    }
        @Override
	public void mostrarAtributos(){
        super.mostrarAtributos();
        System.out.println("atribC: " + this.atribC);
        System.out.println("Igual de C: " + this.igual);
    }
}
