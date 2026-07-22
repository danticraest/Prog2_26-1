public class AtencionFueraHorario extends Atencion {
    @Override
    public String getTipo() {
        return "AtencionFueraHorario";
    }

    @Override
    public double calcularCosto() {
        return 800.00;
    }
}
