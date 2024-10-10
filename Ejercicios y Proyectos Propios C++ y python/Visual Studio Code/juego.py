class Jugador():
    def __init__(self,id,damage,defensa) -> None:
        self.id=id
        self.damage=damage
        self.defensa=defensa

class Premio():
    def __init__(self,incremento_damage,incremento_defensa) -> None:
        self.incremento_damage=incremento_damage
        self.incremento_defensa=incremento_defensa

class Juego():
    def __init__(self) -> None:
        self.jugadores=[]
        self.premios=[]
        
    def enlistar_jugadores(self,jugador: Jugador):
        self.jugadores.append(jugador)

    def enlistar_premios(self,premio: Premio):
        self.premios.append(premio)

    def repartir_premios(self,jugador_actual,jugador_siguiente):

        if jugador_actual.defensa == jugador_siguiente.defensa:
            print("ninguno gano por tanto no hay premiacion")

        if self.premios is not None:

            if jugador_actual.defensa > jugador_siguiente.defensa:
                for premios in self.premios:
                    jugador_actual.damage+=premios.incremento_damage
                    jugador_actual.defensa+=premios.incremento_defensa
            else:
                for premios in self.premios:
                    jugador_siguiente.damage+=premios.incremento_damage
                    jugador_siguiente.defensa+=premios.incremento_defensa

    def enfrentamiento(self):
        for jugador in range(0,len(self.jugadores),2):
            if jugador+1 < len(self.jugadores):
                jugador_actual= self.jugadores[jugador]
                jugador_siguiente= self.jugadores[jugador+1]

                jugador_actual.defensa-=jugador_siguiente.damage #aplicando dano al primer jugador 
                jugador_siguiente.defensa-=jugador_actual.damage #aplicando dano al segundo jugador
                
                self.repartir_premios(jugador_actual,jugador_siguiente)


jugador1=Jugador(123,20,20)
jugador2=Jugador(234,30,30)

#premio1=Premio(10,10)

juego=Juego()

juego.enlistar_jugadores(jugador1)
juego.enlistar_jugadores(jugador2)

#juego.enlistar_premios(premio1)

juego.enfrentamiento()

for juego in juego.jugadores:
    print(juego.damage)
    print(juego.defensa)