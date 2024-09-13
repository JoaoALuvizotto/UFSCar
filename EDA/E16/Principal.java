public class Principal{

    public static void main(String[] args) {
        A a1 = new A('a', 1);
        B b1 = new B('b', 2);
        C c1 = new C('c', 3);
        System.out.println("****************Mostrando atributos do objeto da classe A****************");
        a1.mostrarAtributos();
        System.out.println("****************Mostrando atributos do objeto da classe B****************");
        b1.mostrarAtributos();
        System.out.println("****************Mostrando atributos do objeto da classe C****************");
        c1.mostrarAtributos();
    }
    
}
