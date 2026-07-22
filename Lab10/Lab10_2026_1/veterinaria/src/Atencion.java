import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public abstract class Atencion extends Registro {
    private String dia;
    private int hora;
    private String tipoAtencion;
    private int idPaciente;
    private List<Integer> codigosVacuna;
    private double costoCalculado;
    //agregado por indicaciones en pizarra:
    private Paciente paciente;

    public Atencion() {
        codigosVacuna = new ArrayList<>();
    }

    public boolean leer(Scanner archivo) {
//        dia = archivo.next();
//        hora = archivo.nextInt();
        tipoAtencion = archivo.next();
        idPaciente = archivo.nextInt();
        if (tipoAtencion.equals("VACUNACION")) {
            while (archivo.hasNextInt()) {
                Integer code = archivo.nextInt();
                codigosVacuna.add(code);
            }
        }
//        costoCalculado = archivo.nextDouble();
        return true;
    }

    public void imprimir() {
        System.out.printf("%-30s %-20s %-20s %-15d S/ %-15f\n",
                getTipo(), tipoAtencion, dia, hora, costoCalculado);
    }

    public abstract String getTipo();

    public abstract double calcularCosto();

    public Paciente getPaciente() {
        return paciente;
    }

    public void setPaciente(Paciente paciente) {
        this.paciente = paciente;
    }

    public String getDia() {
        return dia;
    }

    public void setDia(String dia) {
        this.dia = dia;
    }

    public String getTipoAtencion() {
        return tipoAtencion;
    }

    public void setTipoAtencion(String tipoAtencion) {
        this.tipoAtencion = tipoAtencion;
    }

    public int getHora() {
        return hora;
    }

    public void setHora(int hora) {
        this.hora = hora;
    }

    public int getIdPaciente() {
        return idPaciente;
    }

    public void setIdPaciente(int idPaciente) {
        this.idPaciente = idPaciente;
    }

    public List<Integer> getCodigosVacuna() {
        return codigosVacuna;
    }

    public double getCostoCalculado() {
        return costoCalculado;
    }

    public void setCostoCalculado(double costoCalculado) {
        this.costoCalculado = costoCalculado;
    }
}
