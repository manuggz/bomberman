#ifndef JUEGO_HPP
#define JUEGO_HPP
#include <iostream>
using namespace std;
#include <SDL2/SDL.h>
#include "../time.hpp"
#include "../niveles/mapa.hpp"
#include "../engine/util/game_manager.hpp"
#include "../constantes.hpp"
#include "../engine/interfaces/InterfazUI.hpp"
#include "../engine/sprites/CGroup.hpp"
/*Personajes*/
#include "../personajes/bomba.hpp"
#include "../item.hpp"
#include "../explosion.hpp"
#include "../personajes/bloque.hpp"
#include "../engine/util/LTimer.hpp"
#include "../engine/sprites/CDrawGroup.hpp"
#include "juego_historia.hpp"
#include "../engine/interfaces/InterfazGaleria.hpp"
#include "../personajes/player.hpp"
//#define DEBUG



class Juego:public InterfazUI , public InterfazSpriteGroup,public InterfazGaleria{
      public:
        Juego(GameManager * gameManager,int x,int y,int idTerrenoBatalla,int victorias,int minutos,bool isPlayerActivo[_PLAYERS]);
        void procesarEvento(SDL_Event * evento);
        void update ();
        void draw(SDL_Renderer * );

        virtual void killedSprite(Sprite *sprite) override;

    //void estadoDisplayMensage();
        //virtual void estadoPlay()=0;
        virtual void drawBarra(SDL_Renderer *)=0;
       // void displayMensage(const char * mensage);
        //virtual int getEjeXVisual(){return mMapa->getEjeXVisualizacion();};
        //virtual int getEjeYVisual(){return mMapa->getEjeYVisualizacion();};
        //virtual int getAnchoMapa(){return mMapa->getAnchoMapa();};
        //virtual int getAltoMapa(){return mMapa->getAltoMapa();};
        //virtual void resetEjes(){mMapa->setEjeVisualizacion(EjeX,EjeY);};
        //void cargarMapa();
/*
        virtual bool moveLeftEjeXVisual(){
            if(getEjeXVisual()+getAnchoMapa()>W_SCREEN){
                mMapa->moveEjeXVisualizacion(-1);
                moveAllSprites(-1,0);
                return true;
            }
            return false;
        }
        virtual bool moveRightEjeXVisual(){
            if(getEjeXVisual()<0){
                mMapa->moveEjeXVisualizacion(1);
                moveAllSprites(1,0);
                return true;
            }
            return false;
        }
        virtual bool moveDownEjeYVisual(){
            if(getEjeYVisual()<40){
                mMapa->moveEjeYVisualizacion(1);
                moveAllSprites(0,1);
                return true;
            }
            return false;
        }

*/
        void playSfx(CodeMusicEfecto code);
        void playSonido(CodeMusicSonido code);


        //void setPuertaAbierta(bool nuevo);
        //void setPuntaje(IdPlayer id,int nuevo);
        //void setActivos(TipoSprite type,int nuevo);
        //virtual void setMapaPlay(int,bool=false){};
        //void setProteccion(TipoSprite type, int id,int nuevo);
        //void setRepeticionBomba(int id,int nuevo);
        //void setEstadoPlayer(IdPlayer id,EstadoSprite nuevo);

        //void crearReferencias();
        //int addSprite(int type,int x,int y,int lanzador=-1,int otra_var=-1);
        //void addSprite(Sprite * );
        //void erase(int type,int id_sprite);
        //void killSprite(int type,int id_sprite);
        //void soloKill(int type,int id_sprite);
        //void clearSprites(bool elimina_players=false);
        
        //virtual InterfazJuego getTipoJuego()=0;
//        TipoItem getTipoNuevoItem();
        //int getTipoItem(int id_item);
        //int getJoysActivos();
        //int getActivos(TipoSprite type);
        //int getLanzador(TipoSprite type,int id_spri);
        //int getPuntaje(IdPlayer id);
        int getSegundosInicioNivel();
        //int getActivos(TipoSprite type,int & id);
        //int getActivosId(TipoSprite type,IdPlayer  id);
        //int getXPuerta()const{return mMapa->getXPuerta();};
        //int getYPuerta()const{return mMapa->getYPuerta();};
        //int getIdTile()const{return mMapa->getIdTile();};
//        int getNivelActual();
        //void getPosicion(TipoSprite type, int id,int & x,int & y);
        //bool getPuertaAbierta();
//        int getTick(){
//            if(mGameTimer)return mGameTimer->getMiliSegundos();
//        }
//
        LTexture * getImagen(CodeImagen code){ return mGameManager->getImagen(code);};
//        SDL_Joystick * getJoy(int id);
//        virtual int getTipoNuevoItem(bool disminuir_de_mapa=true);
//
//
//        int colision(SDL_Rect & rect_coli,int * lado_colision,bool solo_bloques_duros);
//        int colision(TipoSprite  type[],int tamanyo,SDL_Rect & rect_coli);
//        int colision(TipoSprite type,SDL_Rect & rect_coli,int id_ignorar=-1);
//        int colision(TipoSprite type,SDL_Rect & rect_coli,int & lado_colision,bool solo_bloques_duros);
//
//        bool isBloqueRompible(int x,int y);
//        bool isBloqueDuro(int x,int y);
//        bool isBloqueItem(int x,int y);
//        bool isActivo(TipoSprite type,int id);
//
//        void romperBloque(int x,int y);
//
//        virtual void aumentarNivel(){};
//        void controlaPausa(const Uint8 * keys);
//        void moveAllSprites(int aumX,int aumY);
        virtual ~Juego();

    void prepare() override;

    void createUI(SDL_Renderer *gRenderer) override;

    void start() override;

protected:

    // Controlador del Juego en General(Interfaces,SDL y mainloop)
    GameManager * mGameManager = nullptr;

    // Todos los Sprites en pantalla que se dibujaran
    DrawGroup mGrpSprites;

    Group mGrpEnemigos;
    Group mGrpExplosiones;
    Group mGrpItems;
    Group mGrpBombas;
    Group mGrpPlayers;
    Group mGrpBloques;
    Group mGrpAnimaciones;

    // Solo los players activos
    //Group *mPlayers;

    Mapa * mMapa       = nullptr;
    //Sprite ** refeSprites[_REFERENCIADOS];
    //bool pausado;/*True si el juego esta pausado/si se esta mostrando la imagen de pausa (carita mas pausa)*/
    //bool hold_start;/*_True si un player mantiene start presionado*/
    //int spriteActivos[_REFERENCIADOS],totalSprite[_REFERENCIADOS];
    LTimer *mGameTimer = nullptr;



    int      mRondasGanadas [_PLAYERS] {0};
    int      mPuntajePlayer [_PLAYERS] {0};

    bool     mIsPlayerActivado[_PLAYERS] {false};
    Player * mPlayerSprite  [_PLAYERS] {nullptr};

    int mIDTerrenoMapa = 0;
    int mNVictorias    = 0;
    int mMinutos       = 0;

    //int inicio_pausa; /*almacena el tiempo cuando se inicio la pausa*/

    //IdPlayer id_quien_pauso;/*Almacena el ID del player que acciono la pausa*/
    //IdPlayer id_quien_pauso_anterior;/*Almacena el ID del player que acciono la pausa anteriormente*/

    //EstadoJuego estado,estado_siguiente;

    /*int x_msg,y_msg;
    float vel_y;
    char msg_mostrar[50];
//        int retraso;
    int n_actual;
    bool p_abierta;

    bool animandoEntradaMapaVertical;;
    int desplazamiento;

    int mayor_puntaje;

    //bool _quit;
    //bool patinesLanzados,bombasMaxLanzado,alcanceMaxLanzado;
*/
    //DatNivel * data;
    //int EjeX,EjeY;

    //IdPlayer id_lider_ganadas;

    //bool muertosPorTiempo;


   // bool repro_war,iniciado;
    //int vic,min;

    void crearPlayersActivos();

/*    void setMapaID(int nuevoID);

    void setNVictoriasRule(int nVictorias);


    void setNMinutosRule(int nMinutos);


    void setEstadoActivacionPlayer(IdPlayer player, bool nuevoEstado);*/

    void establecerValoresPlayersDeMapa();

    void agregarPlayersActivos();
};

#endif
