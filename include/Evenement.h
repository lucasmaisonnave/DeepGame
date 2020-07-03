#ifndef EVENEMENT_H
#define EVENEMENT_H

enum KEYS{  KEY_UP = 0, KEY_DOWN = 1,
            KEY_FORWARD = 0, KEY_BACKWARD, KEY_LEFT, KEY_RIGHT,
            KEY_END }; 

class Evenement
{
protected:
    bool TabKey[KEY_DOWN+1][KEY_END];
    bool quit;
    void initTabKey();
    void setTabKey(SDL_Keycode sym, const int UD);
public:
    Evenement();
    ~Evenement();
    /*
        Met à jour le tab des input
    */
    void UpdateEvent();
    /*
        Prend en entrée une touche parmi KEYS
        et rendoie true si la touche a été pressé
    */
    bool IsKeyPressed(const int UpDown, const int Dir) const;    
};

#endif