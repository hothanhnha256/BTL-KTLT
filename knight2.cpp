#include "knight2.h"
/*------------------------BASE ITEM--------------------------*/


Antidote::Antidote() { itemType = Antidot; }
PhoenixDownI::PhoenixDownI() { itemType = PhoenixI; }
PhoenixDownII::PhoenixDownII() { itemType = PhoenixII; }
PhoenixDownIII::PhoenixDownIII() { itemType = PhoenixIII; }
PhoenixDownIV::PhoenixDownIV() { itemType = PhoenixIV; }


/*------------------------END BASE ITEM----------------------*/


/* * * BEGIN implementation of class BaseBag * * */


BaseBag::~BaseBag() {
    while (firstItem != nullptr) {
        BaseItem* item = firstItem;
        firstItem = firstItem->nextItem;
        delete item;
    }
}
void BaseBag::insert(ItemType type) {

    if (count < maxItem)
    {
        BaseItem* tmp = nullptr;
        if (type == Antidot) {
            tmp = new Antidote();
        //    cout << "them Antidote thanh cong!!!\n";
        }
        if (type == PhoenixI) {
            tmp = new PhoenixDownI();
         //   cout << "them phoenixI thanh cong!!!\n";
        }
        if (type == PhoenixII) {
            tmp = new PhoenixDownII();
        }
        if (type == PhoenixIII) {
            tmp = new PhoenixDownIII();
        }
        if (type == PhoenixIV) {
            tmp = new PhoenixDownIV();
        }
        if (tmp != nullptr) {

            BaseItem* F = firstItem;

            tmp->nextItem = F;
            firstItem = tmp;
            count++;

        }
    }
    //cout << "so luong vat pham trong tui hien co la : " << count << endl;
}  //done

//done
bool BaseBag::insertFirst(ItemType type) {
    if (count < maxItem ) { 
        return true;
    }
    else { return false; }
}
BaseItem* BaseBag::get(ItemType itemtype) {
    if (count == 0) { 
      // cout << "Khong co vat pham nao trong tui!!!" << endl;
        return nullptr; 
    }
    BaseItem* vpuse = firstItem;
    for (int i = 0; i < count; i++) {
        if (vpuse->itemType == itemtype) {
            break;
        }
        vpuse = vpuse->nextItem;
    }
    return vpuse;

}

string BaseBag::toString()const {
    BaseItem* head = firstItem;
    string item = "Bag[count=";
    string s = "";
    string k = "";
    for (int i = 0; i < count;i++) {
        if (head != NULL) {
            if (head->itemType == Antidot) { s += "Antidote"; }
            else if (head->itemType == PhoenixI) { s += "PhoenixI"; }
            else if (head->itemType == PhoenixII) { s += "PhoenixII"; }
            else if (head->itemType == PhoenixIII) { s += "PhoenixIII"; }
            else if (head->itemType == PhoenixIV) { s += "PhoenixIV"; }
            if (head->nextItem != nullptr) { s += ","; }
            head = head->nextItem;
        }
    }
    

    k= item + to_string(count) + ";" + s + "]" ;
    return k;
}
void BaseBag::swap(BaseItem** first, BaseItem** Item) {
    BaseItem* tmp = *first;
    *first = *Item;
    *Item = tmp;
}
void BaseBag::changesvadelete (ItemType  Vatphamdung) {
    //           VP
    // 1  2   3  4   5  6
    //   tmp  B  A    
    BaseItem* nodeA = firstItem;
    BaseItem* tmp = nodeA->nextItem;
    BaseItem* nodeB = nullptr;

    if (nodeA->itemType == Vatphamdung) {
        DeleteItem();
    }
    else if (nodeA->nextItem->itemType == Vatphamdung) {
        nodeB = nodeA->nextItem;
        nodeA->nextItem = nodeB->nextItem;
        firstItem = nodeB;
        firstItem->nextItem = nodeA;
        DeleteItem();
    }
    else {
        while (nodeA->itemType != Vatphamdung) {
            if (nodeA == nullptr) { break; }
            nodeB = nodeA;
            nodeA = nodeA->nextItem;
        }
     
        /* get previous Itemuse and Itemuse*/

            BaseItem* F = firstItem;
            /*

              1   2   3   4   5    6   7
              F           B   A    C


              5   2   3   4   1    6   7


            */
            
            F->nextItem=nodeA->nextItem;


            nodeB->nextItem = F;



       
            nodeA->nextItem = tmp;
            
            firstItem = nodeA;

            DeleteItem();

        }
}
void BaseBag::setMaxItem(int maxItem) { this->maxItem = maxItem; }
int BaseBag::getMaxItem() { return maxItem; }
int BaseBag::getCount() { return count; }
void BaseBag::DeleteItem() { 
   //cout << "Xoa vat pham\n";
    BaseItem* tmp = firstItem;
    firstItem = tmp->nextItem; count--; 
    delete tmp;
}

/* --------------------2212345-----------------------END BASEBAG --------------------------HOTHANHNHA  */
/*--------------------------BAT DAU CAC CLASS CON TU BASEBAG 2212345 ----------------------------------*/
// KHOI TAO CAC CLASS ITEM TYPE TU CJNSTRUCTOR K CAN DUBG DEN BASEkNIGHT*)
PaladinBag::PaladinBag (int antidote, int phoenix ) {
    setMaxItem(999);
   // cout << "them tui do paladin thanh cong so luong vat pham la : " << endl;
   // cout << getMaxItem()<<endl;
    if (phoenix > 5) { phoenix = 5; }
    if (antidote > 5) { antidote = 5; }
    for (int i = 0; i < phoenix; i++) {
        insert(PhoenixI);
        
    }
    for (int i = 0; i < antidote; i++) {
        insert(Antidot);
        countA++;
    }
}
LancelotBag::LancelotBag(int antidote, int phoenix) {
    setMaxItem(16);
    if (phoenix > 5) { phoenix = 5; }
    if (antidote > 5) { antidote = 5; }
   // cout << "them tui do lancelot thanh cong so luong vat pham la : " << endl;
   // cout << getMaxItem() << endl;
    for (int i = 0; i < phoenix; i++) {
        insert(PhoenixI);
    }
    for (int i = 0; i < antidote; i++) {
        countA++;
        insert(Antidot);
    }
}
DragonBag::DragonBag(int phoenix){
    setMaxItem(14);
    if (phoenix > 5) { phoenix = 5; }
   // cout << "them tui do dragon thanh cong so luong vat pham la : " << endl;
   // cout << getMaxItem() << endl;
    for (int i = 0; i < phoenix; i++) {
        insert(PhoenixI);
    }
}
bool  DragonBag::insertFirst(ItemType type) {

    if (type == Antidot || getCount() >= getMaxItem()) {
        return false;
    }
    return true;
}
NormalBag::NormalBag(int antidote, int phoenix) {
    setMaxItem(19);
    if (phoenix > 5) { phoenix = 5; }
    if (antidote > 5) { antidote = 5; }
    //cout << "them tui do normal thanh cong so luong vat pham la : " << endl;
   // cout << getMaxItem() << endl;
    for (int i = 0; i < phoenix; i++) {
        insert(PhoenixI);
    }
    for (int i = 0; i < antidote; i++) {
        countA++;
        insert(Antidot);
    }
}
/*----------------------------------KET THUC CAC CLASS CON TU BASEBAG----------------------------*/

/* * * BEGIN implementation of class BaseKnight * * */

string BaseKnight::toString() const {
    string k;
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    if (knightType == PALADIN) { k = typeString[0]; }
    if (knightType == LANCELOT) { k = typeString[1]; }
    if (knightType == DRAGON) { k = typeString[2]; }
    if (knightType == NORMAL) { k = typeString[3]; }

    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + ","    + bag->toString() 
        + ",knight_type:" + k
        + "]";
    return s;
}

BaseKnight* BaseKnight::create(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote) {

    if (isPrime(maxhp)) {
    return new PaladinKnight (id, maxhp, level, phoenixdownI, gil, antidote);
    }
    else if (maxhp == 888) {
    return new LancelotKnight(id, maxhp, level, phoenixdownI, gil, antidote);
    }
    else if (Pythagoras(maxhp)) {
    return new DragonKnight(id, maxhp, level, phoenixdownI, gil, antidote);
    }
    else {
    return new NormalKnight(id, maxhp, level, phoenixdownI, gil, antidote);
    }
}

BaseKnight::BaseKnight(){
    this->id = 0;
    this->maxhp = 0;
    this->hp = 0;
    this->level = 0;
    this->gil = 0;
    this->bag = nullptr;
    this->antidote = 0;
    this->phoenixdownI = 0;
    this->knightType = NORMAL;

}
BaseKnight::BaseKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote) {
    this->id = id;
    this->maxhp = maxhp;
    this->hp = maxhp;
    this->level = level;
    this->gil = gil;
    this->bag = nullptr;
    this->antidote = 0;
    this->phoenixdownI = 0;
    this->knightType = NORMAL;
}
BaseKnight::~BaseKnight() { delete[] bag; }

int BaseKnight::getHP() { return hp; }
int BaseKnight::getMaxHP() { return maxhp; }
int BaseKnight::getLevel() { return level; }
int BaseKnight::getID() { return id; }
int BaseKnight::getGil() { return gil; }

void BaseKnight::setGil(int gil) { this->gil = gil; }
void BaseKnight::setHP(int hp) { this->hp = hp; }
void BaseKnight::setLevel(int level) { this->level = level; }

void BaseKnight::checklevel(){
    if (level > 10) {
        level = 10;
    }
}
void BaseKnight::checkhp() {
    if (hp > maxhp) {
        hp = maxhp;
    }
}
KnightType BaseKnight::getType() { return knightType; }


BaseBag* BaseKnight::getBag() { return bag; }
/* * * END implementation of class BaseKnight * * */

/*----------------------------PhoenixDown1 2 3 4 va ANTIDOTE ----------------------------*/
// con phuong thuc poison va giaidoc
bool Antidote::canUse(BaseKnight* knight) {

    if (knight->getBag()->get(Antidot)!=nullptr && knight->poison == true)
    {
      //  cout << "co the dung Anti\n";
        return true;
    }
    return false;
}
void Antidote::use(BaseKnight* knight) {
    //cout << "Sudung Anti\n";
    knight->poison = false;
}
    // xoa vp
/*--------------4 LENH USE CAN PHAI XOA VAT PHAM NUA-------------*/

bool PhoenixDownI::canUse(BaseKnight* knight) {
    if (knight->getHP() <= 0) {
        //knight->setHP(knight->getMaxHP());
       // cout << "co the dung PI\n";
        return true;
    }
    else {
        return false;
    }
}
void PhoenixDownI::use(BaseKnight* knight) {
   // cout << "SudungPI\n";
    knight->setHP(knight->getMaxHP());

}


bool PhoenixDownII::canUse(BaseKnight* knight) {
    if (knight->getHP() < knight->getMaxHP()/4) {
        //knight->setHP(knight->getMaxHP());
        return true;
    }
    return false;
}
void PhoenixDownII::use(BaseKnight* knight) {
    knight->setHP(knight->getMaxHP());
}


bool PhoenixDownIII::canUse(BaseKnight* knight) {
    if (knight->getHP() <= knight->getMaxHP()/3) {
        //knight->setHP(knight->getMaxHP());
        return true;
    }
    return false;
}
void PhoenixDownIII::use(BaseKnight* knight) {
    if (knight->getHP() <= 0) {
        knight->setHP(knight->getMaxHP()/3);
    }
    else
    {
        knight->setHP(knight->getHP() + knight->getMaxHP() / 4);
    }
}


bool PhoenixDownIV::canUse(BaseKnight* knight) {
    if (knight->getHP() <= knight->getMaxHP()/2) {
        //knight->setHP(knight->getMaxHP());
        return true;
    }
    return false;
}
void PhoenixDownIV::use(BaseKnight* knight) {
    if (knight->getHP() <= 0) {
        knight->setHP(knight->getMaxHP() / 2);
    }
    else
    {
        knight->setHP(knight->getHP() + knight->getMaxHP() / 5);
    }
}


/* * * BEGIN implementation of class ArmyKnights * * */
// khoi tao
ArmyKnights::ArmyKnights(const string& file_armyknights) {
    ifstream file(file_armyknights);
    int count;
    file >> count;
    this->sohiepsi = count;
  //  cout << "so luong hiep si: " << count << endl;
    if (count > 0) {
        Hiepsi = new BaseKnight * [count](); //LOI CHO NAY

        for (int i = 0; i < count; i++) {
            int id = i + 1, maxhp, level, gil, antidote, phoenixdownI;
            file >> maxhp >> level >> gil >> antidote >> phoenixdownI;
            Hiepsi[i] = BaseKnight::create(id, maxhp, level, gil, antidote, phoenixdownI);
          //  cout << "tao hiep si :" << id << " thanh cong!!!" << endl;
         //  cout << Hiepsi[i]->toString() << endl; // loi phan to string();
            //cout << Hiepsi[i]->toString();
        }
    }
}
//xoa heap
ArmyKnights::~ArmyKnights() {
    for (int i = 0; i < sohiepsi; i++) {
        delete Hiepsi[i];
    }
    delete[] Hiepsi;
}


void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}
int ArmyKnights::count() const { return sohiepsi; }
BaseKnight* ArmyKnights::lastKnight()  const {

    if (this->sohiepsi > 0) {
        return *(Hiepsi+sohiepsi-1);
    
    }
    else {return nullptr;}
}

/*---------------------------------HAM CHAY TUNG SU KIEN---------------------------------------------*/
/********************************************VAN CHUA TOI UU***********************************************/

// sai khuc de quy

bool ArmyKnights::fight(BaseOpponent* opponent) {
    BaseKnight* hiepsichiendau = lastKnight();
    bool ketqua = opponent->chiendau(hiepsichiendau);
    hiepsichiendau->checkhp();
    hiepsichiendau->checklevel();
    chuyengildu();
    // neu thang
    if (ketqua) {
        if (opponent->getEventid() == 10) { WinOmega = true; }
        if (opponent->getEventid() == 11) { WinHades = true; Shield = true; }

        return true;// di tiep su kien tiep theo
    }
    else {
        if (hiepsichiendau->getHP() <= 0) {
            /* SU DUNG VAT PHAM DE HOI MAU*/
            if (sudungvatpham()) {
                //co vp va hoi sinh;
                return true;
            }
            else if (hiepsichiendau->getGil() >= 100) {
                hiepsichiendau->setGil(hiepsichiendau->getGil() - 100);
                hiepsichiendau->setHP(hiepsichiendau->getMaxHP() / 2);
                return true;
            }
            else {
  
                sohiepsi=sohiepsi-1;
  
                /* TRUONG HOP HET HIEP SI*/
                if (sohiepsi == 0) { return false; }
                /*TRUONG HOP CON HIEP SI*/
                else {
                    return true;
                }
            }
        }
        /*THUA NHUNG MAU KHONG MAT HET*/
        else {
            sudungvatpham();
            return true;
        }
    }


}
void BaseBag::deleteA() { countA--; }

/*---------------------------------HAM CHAY TOAN BO SU KIEN------------------------------------------*/
bool ArmyKnights::adventure(Events* events) {
  //  cout << "HANH TRINH DANH QUAI HEHEHE" << endl;

    BaseKnight* hiepsichiendau = lastKnight(); // lay dia chi cua hiep si chien dau voi quai vat

    for (int i = 0; i < events->count(); i++) {

        int idsukien = events->get(i);
   //    cout << "su kien thu: " << i + 1 << "_________Ma su kien: " << idsukien << endl;
        BaseOpponent *opponent=nullptr;

        switch (idsukien)
        {
        case 1:
           // cout << "gap quai 1" << endl;
            opponent = new MadBear;
            break;
        case 2:
            //cout << "gap quai 2" << endl;
            opponent = new Bandit;
            break;
        case 3:
            //cout << "gap quai 3" << endl;
            opponent = new LordLupin;
            break;
        case 4:
           // cout << "gap quai 4" << endl;
            opponent = new Elf;
            break;
        case 5:
           // cout << "gap quai 5" << endl;
            opponent = new Troll;
            break;
        case 6:
            opponent = new Tornbery;
            break;
        case 7:
            opponent = new  QueenOfCards;
            break;
        case 8:
            opponent = new NinaDeRings;
            break;
        case 9:
            opponent =new DurianGarden;
            break;
        case 10:// VAN CON LOI SAI
           
            if (!WinOmega) {
                opponent = new OmegaWeapon;
            }
            break;
        case 11: // VAN CON LOI SAI

            if (!WinHades) {
                opponent = new Hades;
            }
            break;

        case 112:
            if (hiepsichiendau->getBag()->insertFirst(PhoenixII)) {
                lastKnight()->getBag()->insert(PhoenixII);
            }
            else {
                chuyenitemdu(PhoenixII);
            }
            break;
        case 113:
            if (hiepsichiendau->getBag()->insertFirst(PhoenixIII)) {
                lastKnight()->getBag()->insert(PhoenixIII);
            }
            else {
                chuyenitemdu(PhoenixIII);
            }
            break;
        case 114:
            if (hiepsichiendau->getBag()->insertFirst(PhoenixIV)) {
                lastKnight()->getBag()->insert(PhoenixIV);
            }
            else {
                chuyenitemdu(PhoenixIV);
            }
            break;
        case 95:
  
            Shield = true;
            break;
        case 96:
   
            Spear = true;
            break;
        case 97:
     
            Hair = true;
            break;
        case 98:
            if (Hair && Shield && Spear) {  Excalibur = true; }
            else {   }
            break;
        case 99:
            //Ultimecia
          //  cout << lastKnight()->toString() << endl;
            if (hasExcaliburSword()) {
           
                printInfo();
                return true;
            }
            else if (hasGuinevereHair() && hasLancelotSpear() && hasPaladinShield()) {
               // cout << "chiendaubang3vp\n";
                int HPBOSS = 5000;
                int so = this->sohiepsi;
                int gg = so;
        
                //if (Hiepsi[0]->getType() == 0) { cout << "PALADINNNNNNNNNNN\n"; }
                for (int k = 0; k < gg; k++) {
                 
                    double basedamage=0;
                    //cai damage
                    if (Hiepsi[gg - k - 1]->getType() == 3) {  so--; continue; }// bo qua hiep si ban tron
                    if (Hiepsi[gg - k - 1]->getType() == 1) {       basedamage = 0.05; }
                    if (Hiepsi[gg - k - 1]->getType() == 0) {        basedamage = 0.06; }
                    if (Hiepsi[gg - k - 1]->getType() == 2) {      basedamage = 0.075; }
          
                   // cout << "danhnhau";
                    int dam = int(Hiepsi[gg-k-1]->getHP() * Hiepsi[gg-k-1]->getLevel() * basedamage);
                    HPBOSS = HPBOSS - dam;
                    //check boss con song k
                    if (HPBOSS > 0) {
                        Hiepsi[gg-k-1]->setHP(0); // hiep si chet
                        so--;
                        sohiepsi--;
                        //delete[] lastKnight();
                    }
                        else {
                        printInfo();
                        return true;
                        }
                    if (so == 0) {
                        sohiepsi = 0;
                        printInfo();
                        return false;
                    }
                }
                if (so == 0) {
                    sohiepsi = 0;
                    printInfo();
                    return false;
                }
         
            }
            else {//k co du 3 bao vat
                sohiepsi = 0;
                printInfo();
                return false;
            }
            break;
        }
        bool kq = true;
        if (opponent != nullptr) {
         //   cout << "chiendau\n";
            opponent->setEventnum(i);
            opponent->setLevelO();
            //cout << "chien dau voi quai vat: " << opponent->getEventid() << endl;
            kq=fight(opponent);
        }
        printInfo();
        if (kq==false) { return false; }
  
        /*
        for (int i = 0; i <= sohiepsi; i++) {
            cout << Hiepsi[i]->toString() << endl;
            cout << "so gil hiep si thu " << i + 1 << endl;
            cout << Hiepsi[i]->getGil() << endl;
            cout << "tui do hiep si thu" << i + 1 << endl;
            cout << Hiepsi[i]->getBag()->toString() << endl;
        }
        */
        delete opponent;
    }
    return true;
}

void ArmyKnights::chuyengildu() {
    if (lastKnight()->getGil() > 999) {
        int tienchuyen = lastKnight()->getGil() - 999;
        lastKnight()->setGil(999);
        for (int i = sohiepsi - 2; i >= 0; i--) {
            BaseKnight* hiepsinhan = Hiepsi[i];
            if (tienchuyen <= 0) { break; }
            if (hiepsinhan->getGil() == 999) { continue; }
            else {
                int moi = hiepsinhan->getGil() + tienchuyen;
                if (moi > 999) {
                    hiepsinhan->setGil(999);
                    tienchuyen = moi - 999;
                }
                else {
                    hiepsinhan->setGil(moi);
                    tienchuyen = 0;
                }
            }
        }
    }
}
void ArmyKnights::chuyenitemdu(ItemType type) {

    for (int i = sohiepsi - 2; i >= 0; i--) {
        BaseKnight* hiepsinhando = Hiepsi[i];
        if ( hiepsinhando->getBag()->insertFirst(type) ) {
            hiepsinhando->getBag()->insert(type);
            break;
        }
    }

}

bool ArmyKnights::sudungvatpham() {
    BaseItem* vatpham = (lastKnight()->getBag()->firstItem);
    int i = 1;
    while (vatpham != nullptr) {
        if (vatpham->canUse(lastKnight()))
        {
            vatpham->use(lastKnight());
            lastKnight()->getBag()->changesvadelete(vatpham->itemType);
            return true;
        }
       vatpham= vatpham->nextItem;
    }
    return false;
}

bool ArmyKnights::hasPaladinShield() const {
    return Shield;
}
bool ArmyKnights::hasLancelotSpear() const {
    return Spear;
}
bool ArmyKnights::hasGuinevereHair() const {
    return Hair;
}
bool ArmyKnights::hasExcaliburSword() const {
    return Excalibur;
}
/* * * END implementation of class ArmyKnights * * */


/* * * BEGIN implementation of clareuss KnightAdventure * * */

//Phuong thuc khoi tao
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;  //gan null
    events = nullptr;
}

void KnightAdventure::loadArmyKnights(const string& file_armyknight) {
    armyKnights = new ArmyKnights(file_armyknight);
}
void KnightAdventure::loadEvents(const string& file_events) {
    events = new Events(file_events);
}

void KnightAdventure::run() {

    bool ketqua=armyKnights->adventure(events);
    armyKnights->printResult(ketqua);

}
/*--------------------------------CHUA HOAN THIEN-----------------------*/


/* * * END implementation of class KnightAdventure * * */

/*--------------------XU LY TUNG CLASS NHAN VAT RIENG BIET-------------------*/
PaladinKnight::PaladinKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote) : BaseKnight(id, maxhp, level, phoenixdownI, gil, antidote) {

    
    
    
   
    knightType = PALADIN;
    bag = new PaladinBag(antidote,phoenixdownI);
}
    LancelotKnight::LancelotKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote) :BaseKnight(id, maxhp, level, phoenixdownI, gil, antidote) {

    knightType = LANCELOT;
    bag = new LancelotBag(antidote,phoenixdownI);
}
   NormalKnight::NormalKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote) :BaseKnight(id, maxhp, level, phoenixdownI, gil, antidote) {

    knightType = NORMAL;
    bag = new NormalBag(antidote, phoenixdownI);
}
    DragonKnight:: DragonKnight (int id, int maxhp, int level, int phoenixdownI, int gil, int antidote) :BaseKnight(id, maxhp, level, phoenixdownI, gil, antidote) {

    knightType = DRAGON;
    bag = new DragonBag(phoenixdownI);
}

/*--------------------KET THUC XU LY TUNG CLASS NHAN VAT RIENG BIET-------------------*/



/*----------------------XU LY CLASS EVENTS-------------------*/
Events::Events(const string& file_events) {
    ifstream file(file_events);
    file >> numEvents;
    events = new int[numEvents];
    for (int i = 0; i < numEvents; i++) {
        file >> events[i];
    }
    file.close();
}
Events::~Events() {
    delete[] events;
}
int Events::count() const {
    return numEvents;
}
int Events::get(int i)const {
        return events[i];
    
}
/*-------------------XU LY XONG CLASS EVENTS -------------------*/

/*-------------------XU LY CAC HAM HO TRO CHO VIEC PHAN NV--------------*/

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
// CHUA HOAN THIEN PYTHAGORAS
bool Pythagoras(int n)
{
    if (n == 543 || n == 534 || n == 354 || n == 345 || n == 435 || n == 453) {
        return true;
    }
    return false;
}

 /*----------------KET THUC XU LY HAM CHECK NV ----------------*/

/*________________________BASEOPPONENT_________________________*/

BaseOpponent::BaseOpponent() {

     levelO = 0;
     baseDamage = 0;
     eventid = 0;
     thutusk = 0;
     gilPoint = 0;
     eventnum = 0;
};

void BaseOpponent::setEventnum(int num) {
    this->eventnum = num;
}
int BaseOpponent::getEventnum() { return eventnum; }
int BaseOpponent::getEventid() { return eventid; }
void BaseOpponent::setLevelO() {
    levelO = ((getEventnum() + eventid) % 10) + 1;
}
/*________________________END BASEOPPONENT_____________________*/

/*________________________CAC OPPONENT CON CUA BASEOPPONENT_____________________________*/
MadBear::MadBear() {
    baseDamage = 10;
    gilPoint = 100;
    eventid = 1;
}
bool MadBear::chiendau(BaseKnight* hiepsichiendau) {


    // DANG LOI
   // cout << "capdoquaivatla" <<levelO << endl;
    if (hiepsichiendau->getLevel() >= levelO || hiepsichiendau->getType() == LANCELOT || hiepsichiendau->getType() == PALADIN) {

        hiepsichiendau->setGil(hiepsichiendau->getGil() + gilPoint);
        return true;
    }
    else {

        int HP = hiepsichiendau->getHP();
        HP = HP - baseDamage * (levelO - hiepsichiendau->getLevel() );
        hiepsichiendau->setHP(HP);
        //cout << "hiepsithuacuoc" << endl;
        //cout << "hiepsithuacuoc" << endl;
        return false;
    }

}

Bandit::Bandit() {
    baseDamage = 15;
    gilPoint = 150;
    eventid = 2;
}
bool Bandit::chiendau(BaseKnight* hiepsichiendau) {

    if (hiepsichiendau->getLevel() >= levelO || hiepsichiendau->getType() == LANCELOT || hiepsichiendau->getType() == PALADIN) {

        hiepsichiendau->setGil(hiepsichiendau->getGil() + gilPoint);
        return true;
    }
    else {

        int HP = hiepsichiendau->getHP();
        HP = HP - baseDamage * (levelO - hiepsichiendau->getLevel());
        hiepsichiendau->setHP(HP);
        return false;
    }

}

LordLupin::LordLupin() {
    baseDamage = 45;
    gilPoint = 450;
    eventid = 3;
}
bool LordLupin:: chiendau(BaseKnight* hiepsichiendau)  {
    if (hiepsichiendau->getLevel() >= levelO || hiepsichiendau->getType() == LANCELOT || hiepsichiendau->getType() == PALADIN) {

        hiepsichiendau->setGil(hiepsichiendau->getGil() + gilPoint);
        return true;
    }
    else {

        int HP = hiepsichiendau->getHP();
        HP = HP - baseDamage * (levelO - hiepsichiendau->getLevel());
        hiepsichiendau->setHP(HP);
        return false;
    }

}

Elf::Elf() {
    baseDamage = 75;
    gilPoint = 750;
    eventid = 4;
}
bool Elf::chiendau(BaseKnight* hiepsichiendau) {
    if (hiepsichiendau->getLevel() >= levelO || hiepsichiendau->getType() == LANCELOT || hiepsichiendau->getType() == PALADIN) {

        hiepsichiendau->setGil(hiepsichiendau->getGil() + gilPoint);
        return true;
    }
    else {

        int HP = hiepsichiendau->getHP();
        HP = HP - baseDamage * (levelO - hiepsichiendau->getLevel());
        hiepsichiendau->setHP(HP);
        return false;
    }

}

Troll::Troll() {
        baseDamage = 95;
        gilPoint = 800;
        eventid = 5;
}
bool Troll::chiendau(BaseKnight* hiepsichiendau)  {
    if (hiepsichiendau->getLevel() >= levelO || hiepsichiendau->getType() == LANCELOT || hiepsichiendau->getType() == PALADIN) {

        hiepsichiendau->setGil(hiepsichiendau->getGil() + gilPoint);
        return true;
    }
    else {

        int HP = hiepsichiendau->getHP();
        HP = HP - baseDamage * (levelO - hiepsichiendau->getLevel());
        hiepsichiendau->setHP(HP);
        return false;
    }

}

Tornbery::Tornbery() {
    eventid = 6;
}
bool Tornbery::chiendau(BaseKnight* hiepsichiendau) {
    // cout << "CHIEN DAU VOI TORNBERY\n";
    if (hiepsichiendau->getLevel() < levelO && hiepsichiendau->getType() != DRAGON) {
        //   cout << "thua cuoc\n";
        hiepsichiendau->poison = true;
        if (hiepsichiendau->getBag()->countA > 0)
        {


            // cout << "co giai\n";
            hiepsichiendau->poison = false;
            hiepsichiendau->getBag()->deleteA();
            hiepsichiendau->getBag()->changesvadelete(Antidot);

        }

        else {
            //  cout << "khong co giai\n";
            for (int i = 0; i < 3; i++) {
                if (hiepsichiendau->getBag()->getCount() <= 0) { break; }
                hiepsichiendau->getBag()->DeleteItem();
            }
            hiepsichiendau->setHP(hiepsichiendau->getHP() - 10);
            if (hiepsichiendau->getHP() <= 0) { return false; }

        }
        //cout << "OK\n";
        hiepsichiendau->poison = false;
        return true;
    }

    else if (hiepsichiendau->getType() == DRAGON && hiepsichiendau->getLevel() < levelO) {
        //  cout << " THUA NMA LA DRAGON\n";
        return true;
    }
    else {
        //  cout << "WIN tornbery\n";
        hiepsichiendau->setLevel(hiepsichiendau->getLevel() + 1);
        return true;
    }

}

QueenOfCards::QueenOfCards() {
    eventid = 7;
}
bool QueenOfCards::chiendau(BaseKnight* hiepsichiendau)  {

    if (hiepsichiendau->getLevel() < levelO ) {
        if (hiepsichiendau->getType() != PALADIN) {
            hiepsichiendau->setGil(hiepsichiendau->getGil() / 2);
        }
        return true;
    }
    else {
        hiepsichiendau->setGil(hiepsichiendau->getGil() * 2);
        return true;
    }
}

NinaDeRings::NinaDeRings() {
    eventid = 8;
}
bool NinaDeRings::chiendau(BaseKnight* hiepsichiendau)  {
    if (hiepsichiendau->getType() == PALADIN) {
        hiepsichiendau->setHP(hiepsichiendau->getHP() + (1 / 5) * hiepsichiendau->getMaxHP());
    }
    else if ( hiepsichiendau->getGil() >= 50 && ( hiepsichiendau->getHP() < int( hiepsichiendau->getMaxHP()/3 ))) {
        hiepsichiendau->setGil(hiepsichiendau->getGil() - 50);
        hiepsichiendau->setHP(hiepsichiendau->getHP() + hiepsichiendau->getMaxHP()/5);
    }
    return true;
}

DurianGarden::DurianGarden() {
    eventid = 9;
}
bool DurianGarden:: chiendau(BaseKnight* hiepsichiendau)   {
    hiepsichiendau->setHP(hiepsichiendau->getMaxHP());
    return true;
}

OmegaWeapon::OmegaWeapon() {
    eventid = 10;
    gilPoint = 999;
}
bool OmegaWeapon::chiendau(BaseKnight* hiepsichiendau) {
    if ((hiepsichiendau->getLevel() == 10 && hiepsichiendau->getHP() == hiepsichiendau->getMaxHP()) || hiepsichiendau->getType() == DRAGON) {
        hiepsichiendau->setLevel(10);
        hiepsichiendau->setGil(999);
        return true;
    }
    else {
        hiepsichiendau->setHP(0);
        return false;
    }
}

Hades::Hades() {
    eventid = 11;
}
bool Hades:: chiendau(BaseKnight* hiepsichiendau)  {
    if (hiepsichiendau->getLevel() == 10 || (hiepsichiendau->getType() == PALADIN && hiepsichiendau->getLevel() >= 8)) {
        return true;
    }
    else {

        hiepsichiendau->setHP(0);
        return false;
    }
}
