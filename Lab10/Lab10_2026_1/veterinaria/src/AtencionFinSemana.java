public class AtencionFinSemana extends Atencion{
    @Override
    public String getTipo() {
        return "AtencionFinSemana";
    }

    @Override
    public double calcularCosto() {
        return 800.00;
    }
}
