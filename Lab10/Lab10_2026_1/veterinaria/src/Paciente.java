import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Paciente extends Registro {
    private int id;
    private String nombre;
    private String especie;
    private int dniTutor;
    private String nombreTutor;
    private List<Atencion> atenciones;
    private double costoTotal;

    public Paciente() {
        atenciones = new ArrayList<>();
    }

    @Override
    public boolean leer(Scanner archivo) {
        id = archivo.nextInt();
        nombre = archivo.next();
        especie = archivo.next();
        dniTutor = archivo.nextInt();
        nombreTutor = archivo.next();
        return true;
    }

    @Override
    public void imprimir() {
        System.out.printf("%d %10s %15s %20d %15s %24.2f\n",
                id, nombre, especie, dniTutor, nombreTutor, costoTotal);
        System.out.printf("%s %20s %20s %20s %20s %20s\n",
                "CLASE_ATENCION", "TIPO", "DIA", "HORA", "VACUNAS", "COSTO");
        for (Atencion a : atenciones) {
            a.imprimir();
        }
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getEspecie() {
        return especie;
    }

    public void setEspecie(String especie) {
        this.especie = especie;
    }

    public int getDniTutor() {
        return dniTutor;
    }

    public void setDniTutor(int dniTutor) {
        this.dniTutor = dniTutor;
    }

    public String getNombreTutor() {
        return nombreTutor;
    }

    public void setNombreTutor(String nombreTutor) {
        this.nombreTutor = nombreTutor;
    }

    public List<Atencion> getAtenciones() {
        return atenciones;
    }

    public double getCostoTotal() {
        return costoTotal;
    }

    public void setCostoTotal(double costoTotal) {
        this.costoTotal = costoTotal;
    }
}
