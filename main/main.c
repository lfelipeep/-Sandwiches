#include <stdio.h>

int main() {
    int opcion, id, cantidad, i;
    int carrito[6] = {0}; 
    int precios[6] = {12000, 15000, 18000, 20000, 22000, 25000};
    char *productos[6] = {
        "Sandwich Jamon/Queso + Papas",
        "Sandwich Pollo + Ensalada", 
        "Sandwich Carne + Papas",
        "Sandwich Vegetariano + Jugo",
        "Sandwich Mixto + Gaseosa",
        "Sandwich Especial + Combo completo"
    };
    int total = 0;
    int domicilio = 4000;

    printf("=== APP DOMICILIOS SANDWICHES ===\n");

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Ver menu de sandwiches\n");
        printf("2. Agregar sandwich al carrito\n");
        printf("3. Ver carrito y total\n");
        printf("4. Confirmar pedido\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: 
                printf("\n=== MENU DE SANDWICHES ===\n");
                for(i = 0; i < 6; i++) {
                    printf("%d. %s - $%d\n", i+1, productos[i], precios[i]);
                }
                break;

            case 2: 
                printf("\n=== AGREGAR SANDWICH ===\n");
                printf("Ingrese el ID del sandwich (1-6): ");
                scanf("%d", &id);
                
                if(id < 1 || id > 6) {
                    printf("ID invalido. Debe ser entre 1 y 6.\n");
                    break;
                }
                
                printf("Cuantas unidades de '%s'? ", productos[id-1]);
                scanf("%d", &cantidad);
                
                if(cantidad <= 0) {
                    printf("Cantidad debe ser mayor a 0.\n");
                    break;
                }
                
                carrito[id-1] += cantidad;
                printf("¡Agregado al carrito!\n");
                break;

            case 3: 
                printf("\n=== CARRITO DE COMPRAS ===\n");
                total = 0;
                
                for(i = 0; i < 6; i++) {
                    if(carrito[i] > 0) {
                        int subtotal = carrito[i] * precios[i];
                        printf("%d x %s = $%d\n", carrito[i], productos[i], subtotal);
                        total += subtotal;
                    }
                }
                
                if(total == 0) {
                    printf("Carrito vacio.\n");
                } else {
                    printf("Subtotal: $%d\n", total);
                    printf("Domicilio: $%d\n", domicilio);
                    printf("TOTAL: $%d\n", total + domicilio);
                }
                break;

            case 4: 
                total = 0;
                for(i = 0; i < 6; i++) {
                    total += carrito[i] * precios[i];
                }
                
                if(total == 0) {
                    printf("No hay sandwiches en el carrito.\n");
                } else {
                    printf("\n=== CONFIRMAR PEDIDO ===\n");
                    printf("Total a pagar: $%d\n", total + domicilio);
                    printf("¡Pedido confirmado! Gracias por su compra.\n");
                    
                    
                    for(i = 0; i < 6; i++) {
                        carrito[i] = 0;
                    }
                }
                break;

            case 5: 
                printf("¡Gracias por usar nuestro servicio de sandwiches!\n");
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

    } while(opcion != 5);

    return 0;

}
