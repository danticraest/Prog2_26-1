import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Veterinaria {
    private List<Paciente> pacientes;
    private List<Atencion> atenciones;
    private Scanner archivo;

    public Veterinaria(String nombreArchivo) throws FileNotFoundException {
        pacientes = new ArrayList<>();
        atenciones = new ArrayList<>();
        archivo = new Scanner(new File(nombreArchivo));
    }

    public void cargarDatos() {
        cargarPacientes();
        cargarAtenciones();
    }

    private void cargarPacientes() {
        while (archivo.hasNextInt()) {
            Paciente pac = new Paciente();
            pac.leer(archivo);
            pacientes.add(pac);
        }
        archivo.next(); //leer el FIN
    }

    private void cargarAtenciones() {
        while (archivo.hasNext()) {
            String diaElegido = archivo.next();
            int horaElegido = archivo.nextInt();
            Atencion ate = insertarTipo(diaElegido, horaElegido);
            ate.setDia(diaElegido);
            ate.setHora(horaElegido);
            ate.leer(archivo);
            atenciones.add(ate);
        }
    }

    private Paciente busqPaciente(int idPac) {
        for (Paciente p : pacientes) {
            if (p.getId() == idPac) return p;
        }
        return null;
    }

    private Atencion insertarTipo(String diaElegido, int horaElegido) {
        switch (diaElegido) {
            case "Lunes", "Martes", "Miercoles", "Jueves", "Viernes":
                if (horaElegido >= 6 && horaElegido <= 19) return new AtencionRegular();
                else return new AtencionFueraHorario();
            default:
                return new AtencionFinSemana();
        }
    }

    public void procesarDatos() {
        for(Atencion ate: atenciones) {
            Paciente pacID = busqPaciente(ate.getIdPaciente());
            ate.setPaciente(pacID);
            pacID.getAtenciones().add(ate);
//            atenciones.add(ate);
        }
    }

    public void imprimirReporte() {
        System.out.printf("==========================================================================\n");
        System.out.printf("%50s\n", "REPORTE DE ATENCIONES VETERINARIA");
        System.out.printf("==========================================================================\n");
        System.out.printf("%s %10s %15s %20s %20s %20s\n",
                "ID", "NOMBRE", "ESPECIE", "DNI_TUTOR", "NOMBRE_TUTOR", "TOTAL");
        for (Paciente p : pacientes) {

            System.out.printf("--------------------------------------------------------------------------\n");
            p.imprimir();
        }
    }
}
