#include "dllomauikomponentti.h"


bool DLLOmaUIKomponentti::rajapintafunktioDLLOmaUIKomponentti()
{
    olioOmaUIMoottoriDialog = new OmaUIMoottoriDialog;
    olioOmaUIMoottoriDialog->show();
    olioOmaUIMoottoriDialog->exec();
    bool status = olioOmaUIMoottoriDialog->returnStatus();
    return status;

    delete olioOmaUIMoottoriDialog;
}
