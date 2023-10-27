#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"
// #define DEBUG
class BaseBag;
class BaseItem;
class Antidote;
class PhoenixDownI;
class PhoenixDownII;
class PhoenixDownIII;
class PhoenixDownIV;
class Events;
class BaseKnight;
class ArmyKnights;
class KnightAdventure;
class Events;
class BaseOpponent;
enum ItemType {
    Antidot=0, PhoenixI,
    PhoenixII, PhoenixIII, PhoenixIV, Nhacutehehe
};
enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };

//cac ham kiem tra hiep si
bool isPrime(int n);

bool Pythagoras(int n);



class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;
    BaseBag* bag;
    KnightType knightType;

public:
    BaseKnight (); // khoi tao voi thong so mac dinh la 0;
    BaseKnight (int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    ~BaseKnight();
    static BaseKnight* create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);// khoi tao voi thong so cho truoc
    KnightType getType();// tra ve kieu nhan vat

    int getHP();
    void setHP(int hp);
    int getMaxHP();
    int getGil();
    void setGil(int gil);
    int getLevel();
    void setLevel(int level);
    int getID();

    string toString() const;

    void checklevel(); // kiem tra lv neu lv >10 thi ve 10
    void checkhp();// ktra hp neu hp>999 thi ve 999
    BaseBag* getBag(); // tra ve tui do 
    bool poison = false;
    // Ham nay chua hoan thien

};

//4 loai hiep si
class PaladinKnight : public BaseKnight {
private:

public:
    PaladinKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);

};

class LancelotKnight: public BaseKnight {
private:
public:
    LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
};

class DragonKnight:public BaseKnight {
private:
public:
    DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
};

class NormalKnight:public BaseKnight {
private:
public:
    NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
};

class ArmyKnights {
private:
    int sohiepsi;
    BaseKnight** Hiepsi = nullptr;
    bool Hair = false;
    bool Spear = false;
    bool Excalibur = false;

public:
    bool Shield = false;

    ArmyKnights(const string& file_armyknights);
    virtual ~ArmyKnights();
    
    bool fight(BaseOpponent* opponent);//METHOD NAY TRA VE HIEP SI CUOI CUNG THANG HAY THUA TRONG 1 SU KIEN, NEU THUA HIEP SI DUNG TRUOC LEN THAY THE

    // CHUA HOAN THIEN

    bool adventure(Events* events);//METHOD NAY TRA VEsudungvatpham DOI QUAN HIEP SI THANG HAY THUA SAU TOAN BO SU KIEN

    int count() const;

    BaseKnight* lastKnight()  const;
    void chuyengildu(); //DONE
    void chuyenitemdu(ItemType type); //DONE

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    bool WinOmega = false;
    bool WinHades = false;
    
    void printInfo() const;
    void printResult(bool win) const;

    bool sudungvatpham();// su dung vat pham dau tien nhat duoc
};

class Events {
private:
    int* events;
    int numEvents;
public:

    Events(const string& file_events);// nap file event vao ctrinh
    ~Events();//delete

    int count() const ; //tra ve so luong su kien

    int get(int i) const; // tra ve ma sk o vi tri i
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights; // armyKnights la 1 con tro

    Events * events; // events la 1 con tro

public:
    KnightAdventure();
    //~KnightAdventure(); // TODO:

    void loadArmyKnights(const string& file_armyknight);

    void loadEvents(const string& file_events);
    void run();
};

class BaseItem {
public:
    ItemType itemType=Nhacutehehe;
    BaseItem* nextItem=nullptr;
    virtual bool canUse(BaseKnight* knight)=0 ;
    virtual void use(BaseKnight* knight) =0 ; 
    virtual ~BaseItem() {}
};

/*-------------------------CAC CLASS VATPHAM CU THE---------------------*/
class Antidote : public BaseItem {
private:

public:
  
    Antidote();
    bool canUse(BaseKnight* knight) override ;
    void use(BaseKnight* knight) override ;
};

class PhoenixDownI : public BaseItem {
public:
    PhoenixDownI();
    //~PhoenixDownI();
    bool canUse(BaseKnight* knight) override;
    void use(BaseKnight* knight) override;
};
class PhoenixDownII : public BaseItem {
public:
  
    PhoenixDownII();
    //~PhoenixDownII();
    bool canUse(BaseKnight* knight) override;
    void use(BaseKnight* knight) override;
};
class PhoenixDownIII : public BaseItem {
public:
    PhoenixDownIII();
    //~PhoenixDownIII();
    bool canUse(BaseKnight* knight) override;
    void use(BaseKnight* knight) override;
};
class PhoenixDownIV :public BaseItem {
public:
    PhoenixDownIV();
    //~PhoenixDownIV();
    bool canUse(BaseKnight* knight) override;
    void use(BaseKnight* knight) override;
};
/*------------------------KET THUC CLASS VAT PHAM CU THE--------------------*/
/*--------------------------TUI DO-------------------------------*/

class BaseBag {
private:
    int maxItem=0;
    int count=0;
 
    //BaseKnight* knight=nullptr;
public:
    //BaseBag();
    //BaseBag (BaseKnight* knight);
    //BaseBag();
    ~BaseBag();//ok
    BaseItem * firstItem = nullptr; // head
    virtual void insert(ItemType type); // THEM VAT PHAM VAO DAU DS
    int getCount();
    virtual bool insertFirst(ItemType type);
    // tra ve con tro tro den vp can su dung
    BaseItem* get(ItemType itemtype);
    //xuat vp
    virtual string toString() const;
    // xoa vp o dau
    void DeleteItem();
    //change doi vi tri vat pham dau tien voi vp can su dung
    void changesvadelete(ItemType type);

    //cai dat MaxItem cho tung nv va lay so do ra
    void setMaxItem(int maxItem);
    int getMaxItem();
    int countA = 0;
    void deleteA();
    void swap(BaseItem** first, BaseItem** Item);
};
   
/*--------------------------------------CAN THUC HIEN LAI CACH KHOI TAO CHO TUNG BAG--------------------------*/
class PaladinBag : public BaseBag {
public:
    PaladinBag(int , int );
};
class LancelotBag : public BaseBag {
public:
    LancelotBag(int antidote, int phoenix);
};
class DragonBag : public BaseBag {
public:
    DragonBag(int phoenix);
    bool insertFirst(ItemType type);   
};
class NormalBag : public BaseBag {
public:
    NormalBag(int antidote, int phoenix);
};
/*-----------------------------KETTHUC---------------------------*/

/*---------------------------------DOI THU--------------------------*/

class BaseOpponent {
protected:
        int levelO;
        int baseDamage;
        int eventid;
        int thutusk;
        int gilPoint;
        int eventnum;
public:

    BaseOpponent();
    virtual bool chiendau(BaseKnight*hiepsichiendau) =0;
    int getEventid();
    void setEventnum(int num);
    int getEventnum();
    void setLevelO();
};
/*---------CON VIEC HOI PHUC HP DUA VAO BAG NUA------------*/
class MadBear :public BaseOpponent {
public:
    MadBear();
    bool chiendau(BaseKnight* hiepsichiendau) override;

};
class Bandit :public BaseOpponent {
public:
    Bandit();
    bool chiendau(BaseKnight* hiepsichiendau) override;
};
class LordLupin :public BaseOpponent {
public:
    LordLupin();
    bool chiendau(BaseKnight* hiepsichiendau) override;
};
class Elf :public BaseOpponent {
private:
public:
    Elf();
    bool chiendau(BaseKnight* hiepsichfiendau) override;

};
class Troll :public BaseOpponent {
private:

public:
    Troll();
    bool chiendau(BaseKnight* hiepsichiendau) override;
};

class Tornbery :public BaseOpponent {
private:

public:
    Tornbery();
    bool chiendau(BaseKnight* hiepsichiendau)  override;
};


class QueenOfCards :public BaseOpponent {
private:
public:
    QueenOfCards();
    bool chiendau(BaseKnight* hiepsichiendau) override;

};
class NinaDeRings :public BaseOpponent {
private:
public:
    NinaDeRings();
    bool chiendau(BaseKnight* hiepsichiendau) override;

};
class DurianGarden :public BaseOpponent {
private:
public:
    DurianGarden();
    bool chiendau(BaseKnight* hiepsichiendau)  override;
};
class OmegaWeapon :public BaseOpponent {
private:
    int countOmega = 1;
public:
    OmegaWeapon();  
    bool chiendau(BaseKnight* hiepsichiendau) override;

};
class Hades :public BaseOpponent {
private:
    int countHades = 1;
public:
    Hades();
    bool chiendau(BaseKnight* hiepsichiendau) override;

};

/*---------------------------------KET THUC DOI THU------------------------*/

#endif // __KNIGHT2_H__