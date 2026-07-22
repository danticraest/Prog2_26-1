public class AtencionRegular extends Atencion{
    @Override
    public String getTipo() {
        return "AtencionRegular";
    }

    @Override
    public double calcularCosto() {
        return 500.00;
    }
}
