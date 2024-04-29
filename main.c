#include <stdio.h>
#include <string.h>

#define VERSION 0.0.3;

struct pokemon {
    char name[40];
    int atk;
    int def;
    int spd;
};

int min(int a, int b) {
    return a < b ? a : b;
}

void searchBattle()
{
    printf("no implementado xdxdxd");
}

void defaultPokes(struct pokemon *listaPokemons)
{
    strcpy(listaPokemons[0].name, "Aerodactyl");
    listaPokemons[0].atk = 30;
    listaPokemons[0].def = 12;
    listaPokemons[0].spd = 40;
    
    strcpy(listaPokemons[1].name, "Metagross");
    listaPokemons[1].atk = 42;
    listaPokemons[1].def = 26;
    listaPokemons[1].spd = 12;
    
    strcpy(listaPokemons[2].name, "Starmie");
    listaPokemons[2].atk = 25;
    listaPokemons[2].def = 25;
    listaPokemons[2].spd = 36;
    
    strcpy(listaPokemons[3].name, "Jolteon");
    listaPokemons[3].atk = 26;
    listaPokemons[3].def = 19;
    listaPokemons[3].spd = 40;
    
    strcpy(listaPokemons[4].name, "Tyranitar");
    listaPokemons[4].atk = 40;
    listaPokemons[4].def = 22;
    listaPokemons[4].spd = 18;
    
    strcpy(listaPokemons[5].name, "Skarmory");
    listaPokemons[5].atk = 14;
    listaPokemons[5].def = 36;
    listaPokemons[5].spd = 21;
}

void defaultOwned(struct pokemon *equipoPokemon)
{
    strcpy(equipoPokemon[0].name, "Raichu");
    equipoPokemon[0].atk = 23;
    equipoPokemon[0].def = 26;
    equipoPokemon[0].spd = 31;
    
    strcpy(equipoPokemon[1].name, "Flygon");
    equipoPokemon[1].atk = 30;
    equipoPokemon[1].def = 25;
    equipoPokemon[1].spd = 24;
}

void removePokemonFromArray(struct pokemon *arrayPokemon, int pokemonIndex, int *pokemonsInShop)
{
    if (pokemonIndex < 0 || pokemonIndex >= *pokemonsInShop)
    {
        printf("index fuera de rango --- manden foto si sale esto :'v\n");
        return;
    }

    printf("Borrando a %s del array. Además hay %d pokemons en la tienda\n", arrayPokemon[pokemonIndex].name, *pokemonsInShop);
    for (int i = pokemonIndex; i < *pokemonsInShop - 1; i++)
    {
        arrayPokemon[i] = arrayPokemon[i + 1];
    }

    (*pokemonsInShop)--;

    printf("Ahora %s ocupa su lugar. Ahora quedan %d pokemons en la tienda\n", arrayPokemon[pokemonIndex].name, *pokemonsInShop);
}

void lineBreak(int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("\n");
    }
}

int displayStruct(struct pokemon *listaPokemons, int *arraySize, char *headerText)
{
    lineBreak(4);
    printf("%s\n", headerText);
    for (int i = 0; i < *arraySize; i++)
    {
        printf("%d .- : %s\n", i, listaPokemons[i].name);
    }
}

int buyPokemon(struct pokemon *listaPokemons, int pokemonIndex, int *pokemonsInShop, struct pokemon *pokemonsComprados, int *pokemonsOwned)
{
    lineBreak(3);
    printf("Felicidades!\n");
    printf("Has comprado a %s exitosamente.\n", listaPokemons[pokemonIndex].name);
    lineBreak(1);
    
    strcpy(pokemonsComprados[*pokemonsOwned].name, listaPokemons[pokemonIndex].name);
    pokemonsComprados[*pokemonsOwned].atk = listaPokemons[pokemonIndex].atk;
    pokemonsComprados[*pokemonsOwned].def = listaPokemons[pokemonIndex].def;
    pokemonsComprados[*pokemonsOwned].spd = listaPokemons[pokemonIndex].spd;
    (*pokemonsOwned)++;
    removePokemonFromArray(listaPokemons, pokemonIndex, pokemonsInShop);
}

int displayPokemonStats(struct pokemon *listaPokemons, int pokemonIndex, int *pokemonsInShop, struct pokemon *pokemonsComprados, int *pokemonsOwned)
{
    int option = -1;
    lineBreak(3);
    printf("----- Estadisticas de %s -------\n", listaPokemons[pokemonIndex].name);
    printf("ATK: %d\n", listaPokemons[pokemonIndex].atk);
    printf("DEF: %d\n", listaPokemons[pokemonIndex].def);
    printf("SPEED: %d\n", listaPokemons[pokemonIndex].spd);
    lineBreak(2);
    
    printf("-- ¿Qué deseas hacer? --\n");
    printf("1 .- Comprar\n2 .- Cancelar\n");
    scanf("%d", &option);
    switch(option)
    {
        case 1:
        buyPokemon(listaPokemons, pokemonIndex, pokemonsInShop, pokemonsComprados, pokemonsOwned);
        break;
        
        default:
        printf("Cancelando...");
    }
}

int buyPokemonMenu(struct pokemon *listaPokemons, int *pokemonsInShop, struct pokemon *pokemonsComprados, int *pokemonsOwned)
{
    if (*pokemonsInShop <= 0)
    {
        lineBreak(3);
        printf("---- No quedan Pokemon disponibles ----");
        lineBreak(2);
        return 0;
    }
    
    int option = -1;
    char pkmnHeader[] = " ----  Pokemon Disponibles  ----";
    int selectedMonIndex = -1;
    
    displayStruct(listaPokemons, pokemonsInShop, pkmnHeader);
    
    printf("Selecciona un Pokemon (inserta numero): ");
    scanf("%d", &option);
    
    selectedMonIndex = option;
    
    lineBreak(2);
    printf("Has elegido: %s\n", listaPokemons[option].name);
    lineBreak(2);
    
    option = -1;
    printf("-- ¿Qué deseas hacer? --\n");
    printf("1 .- Comprar\n2 .- Ver Estadisticas\n3 .- Cancelar\n");
    scanf("%d", &option);
    switch(option)
    {
        case 1:
        buyPokemon(listaPokemons, selectedMonIndex, pokemonsInShop, pokemonsComprados, pokemonsOwned);
        break;
        
        case 2:
        displayPokemonStats(listaPokemons, selectedMonIndex, pokemonsInShop, pokemonsComprados, pokemonsOwned);
        break;
        
        default:
        printf("Cancelando...");
    }
}

int sellPokemonMenu()
{
    lineBreak(2);
    printf("Esta función aún no está implementada.");
    lineBreak(1);
}

int displayTeam(struct pokemon *equipoPokemon, int *pokemonsInTeam)
{
    if (*pokemonsInTeam <= 0)
    {
        lineBreak(2);
        printf("No tienes ningún equipo creado.");
        lineBreak(1);
        return 0;
    }

    int option = -1;
    char pkmnHeader[] = "--- Equipo Pokemon ---";
    displayStruct(equipoPokemon, pokemonsInTeam, pkmnHeader);

    lineBreak(1);
    printf("---- ¿Qué deseas hacer? ----\n");
    printf("1 .- Volver\n");
    scanf("%d", &option);
}

int editTeamMenu(struct pokemon *pokemonsComprados, int *pokemonsOwned, struct pokemon *equipoPokemon, int *pokemonsInTeam)
{
    int option = -1;
    int maxPokemons = min(*pokemonsOwned, 6);
    char pkmnHeader[] = "--- Pokemon Disponibles ---";
    displayStruct(pokemonsComprados, pokemonsOwned, pkmnHeader);

    lineBreak(2);
    printf("---- ¿Qué deseas hacer? ----\n");
    printf("1 .- Editar Equipo\n2 .- Volver\n");
    scanf("%d", &option);
    if (option == 1)
    {
        *pokemonsInTeam = 0;
        printf("%d", *pokemonsInTeam);
        for (int i = 0; i < maxPokemons; i++)
        {
            int index;
            displayStruct(pokemonsComprados, pokemonsOwned, pkmnHeader);
            lineBreak(2);
            printf("--- Selecciona un Pokemon para la posición %d ---\n", i+1);
            scanf("%d", &index);

            if (index == -1) break;
            strcpy(equipoPokemon[i].name, pokemonsComprados[index].name);
            equipoPokemon[i].atk = pokemonsComprados[index].atk;
            equipoPokemon[i].def = pokemonsComprados[index].def;
            equipoPokemon[i].spd = pokemonsComprados[index].spd;
            printf(equipoPokemon[i].name);
            (*pokemonsInTeam)++;
        }
    }
}

int main()
{   
    int close = 0;
    int option = -1;
    struct pokemon listaPokemons[99];
    struct pokemon pokemonsComprados[99];
    struct pokemon equipoPokemon[6];
    
    int pokemonsInShop = 6;
    int pokemonsOwned = 2;
    int pokemonsInTeam = 0;
    
    defaultPokes(listaPokemons);
    defaultOwned(pokemonsComprados);
    
    do
    {
        lineBreak(1);
        printf("------- Pokemon Simulator (por mi jej) --------------\n");
        printf("1 .- Comprar Pokemon\n2 .- Mostrar Equipo Actual\n");
        printf("3 .- Editar Equipo\n4 .- Pelea inhumana\n");
        scanf("%d", &option);
        
        switch(option)
        {
            case 0:
            printf("ADIOS MUNDO\n");
            close = 1;
            break;
            
            case 1:
            buyPokemonMenu(listaPokemons, &pokemonsInShop, pokemonsComprados, &pokemonsOwned);
            break;
            
            case 2:
            displayTeam(equipoPokemon, &pokemonsInTeam);
            break;
            
            case 3:
            editTeamMenu(pokemonsComprados, &pokemonsOwned, equipoPokemon, &pokemonsInTeam);
            break;
            
            case 4:
            searchBattle();
            break;
            
            default:
            printf("La opción no es válida.");
        }
    } while (close == 0);
    
    return 0;
}
