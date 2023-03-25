#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "hospital.hpp"

using namespace std;

int verifica_patient_construtor(Patient **p1)
{
    int er = 0;
    string teste="João";
    tm timeptr{};
    timeptr.tm_year=2000;
    timeptr.tm_mday=3;
    timeptr.tm_mon=2;
   
    *p1 = new Patient("1023412", teste,"1045656",mktime(&timeptr), 'M',1,mktime(&timeptr));
    
    /*Teste 1*/
    if ((*p1) == NULL)
    {
        cout << "...verifica_patient_construtor: Patient e' NULL (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_patient_construtor: Patient nao e' NULL (ok)" << endl;

    /*Teste 2*/
    if ((*p1)->getPersonId()!="1023412")
    {
        cout << "...verifica_patient_construtor: Person Id (= " << (*p1)->getPersonId() << ") e' diferente do esperado (= 1023412) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_patient_construtor: Person Id coincide com o esperado (= 1023412) (ok)" << endl;

    /*Teste 3*/
    if ((*p1)->getName()!=teste) 
    {
        cout << "...verifica_patient_construtor: Nome do Paciente (= " << (*p1)->getName()<< ") e' diferente do esperado (=João) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_patient_construtor: Nome do Paciente coincide com o esperado (= João) (ok)" << endl;
    
    /*Teste 4*/
    if ((*p1)->getPatientId()!= "1045656")
    {
        cout << "...verifica_patient_construtor: Patient Id (= " << (*p1)->getPatientId() <<") e' diferente do esperado (= 1045656) (ERRO)" <<endl;
        er++;
    }
    else
        cout << "...verifica_patient_construtor: Patient Id coincide com o esperado (= 1045656) (ok)" <<endl;    
    
    /*Teste 5*/
    if ((*p1)->getSex() != 'M' )
    {
        cout << "...verifica_patient_construtor: sexo do Paciente (= "<< (*p1)->getSex() <<") e' diferente do esperado (=M) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_patient_construtor: sexo do Paciente coincide com o esperado (= M) (ok)" << endl;

    return er;
}

int verifica_patient_setters(Patient **p1)
{
    int er = 0; 
    if (!(*p1)) {
        cout << "...verifica_patient_setters: Paciente e' NULL (ERRO)" << endl;
        return 1;
    }

    (*p1)->setName("Paula");
    (*p1)->setPatientId("1200900"); 
    (*p1)->setSex('F');

    if ((*p1)->getName()!="Paula") 
    {
        cout << "...verifica_patient_setters: Nome do Paciente (= " << (*p1)->getName()<< ") e' diferente do esperado (=Paula) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_patient_setters: Nome do Paciente coincide com o esperado (= Paula) (ok)" << endl;

    if ((*p1)->getPatientId()!= "1200900")
    {
        cout << "...verifica_patient_setters: Patient Id (= " << (*p1)->getPatientId() <<") e' diferente do esperado (= 1200900) (ERRO)" <<endl;
        er++;
    }
    else
        cout << "...verifica_patient_setters: Patient Id coincide com o esperado (= 1200900) (ok)" <<endl;    

    if ((*p1)->getSex() != 'F' )
    {
        cout << "...verifica_patient_construtor: sexo do Paciente (= "<< (*p1)->getSex() <<") e' diferente do esperado (=F) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_patient_construtor: sexo do Paciente coincide com o esperado (= F) (ok)" << endl;

    return er;
}
int verifica_patient_addVemergency(Patient **p1)
{
    int er = 0; 
    if (!(*p1)) {
        cout << "...verifica_patient_addVemergency: Paciente e' NULL (ERRO)" << endl;
        return 1;
    }
    (*p1)->addVemergency(3);
    (*p1)->addVemergency(2);
    if ((*p1)->getVemergency().size() != 3 )
    {
        cout << "...verifica_patient_addVemergency: numero de entradas do Paciente(= "<< (*p1)->getVemergency().size() <<") e' diferente do esperado (=3) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_patient_addVemergency: numero de entradas do Paciente coincide com o esperado (= 3) (ok)" << endl;

    if ((*p1)->getVemergency()[(*p1)->getVemergency().size()-1] != 2 )
    {
        cout << "...verifica_patient_addVemergency: Tipo de emergencia da última entrada (= "<< (*p1)->getVemergency()[(*p1)->getVemergency().size()-1]  <<") e' diferente do esperado (=2) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_patient_addVemergency: Tipo de emergencia da última entrada coincide com o esperado (= 2) (ok)" << endl;

    return er;
}

int verifica_patient_addVentrance(Patient **p1)
{
    int er = 0; 
    if (!(*p1)) {
        cout << "...verifica_patient_addVentrance: Paciente e' NULL (ERRO)" << endl;
        return 1;
    }
    tm timeptr{};
    timeptr.tm_year=2020;
    timeptr.tm_mday=3;
    timeptr.tm_mon=2;
    (*p1)->addVentrance(mktime(&timeptr));
   
    if ((*p1)->getVentrance().size() != 2 )
    {
        cout << "...verifica_patient_addVentrance: numero de entradas do Paciente(= "<< (*p1)->getVentrance().size() <<") e' diferente do esperado (=2) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_patient_addVentrance: numero de entradas do Paciente coincide com o esperado (= 2) (ok)" << endl;

    if ((*p1)->getVentrance()[(*p1)->getVentrance().size()-1] != mktime(&timeptr) )
    {
        cout << "...verifica_patient_addVentrance: Tipo de emergencia da última entrada (= "<< (*p1)->getVentrance()[(*p1)->getVentrance().size()-1]  <<") e' diferente do esperado (="<<mktime(&timeptr)<<") (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_patient_addVentrance: Ultima entrada coincide com o esperado (= "<<mktime(&timeptr)<<") (ok)" << endl;

    return er;
}

int verifica_PatientManagement_construtor(PatientManagement **pm)
{
    int er = 0;

    *pm = new PatientManagement(); 

    if (!(*pm))
    {
        cout << "...verifica_PatientManagement_construtor: PatientManagement e' NULL (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_PatientManagement_construtor: PatientManagement nao e' NULL (ok)" << endl;

    return er;
}



int verifica_paciente_insere(PatientManagement **pm)
{
    int er = 0, erro = 0;
    
    tm timeptr{};
    timeptr.tm_year=2000;
    timeptr.tm_mday=3;
    timeptr.tm_mon=3;
   
    Patient *p1 = new Patient("123456", "Tiago", "1234345", mktime(&timeptr),'M',2,mktime(&timeptr));
    Patient *p2 = new Patient("108978", "Luis", "12345565", mktime(&timeptr),'M',1,mktime(&timeptr));
    Patient *p3 = new Patient("123456", "Tiago", "1234345", mktime(&timeptr),'M',2,mktime(&timeptr));

    /* Inserir Doente 1*/ 
    erro = (*pm)->patientInsert(p1);
    if (erro == -1)
    {
        cout << "...verifica_paciente_insere: nao conseguiu inserir (ERRO)" << endl;
        return 1;
    }

    /* Inserir Doente 2 */
    erro = (*pm)->patientInsert(p2);
    if (erro == -1)
    {
        cout << "...verifica_paciente_insere: nao conseguiu inserir (ERRO)" << endl;
        return 1;
    }

    /* Inserir Doente 3 */
    erro = (*pm)->patientInsert(p3);
    if (erro != 1)
    {
        cout << "...verifica_paciente_insere: nao conseguiu inserir corretamente (ERRO)" << endl;
        return 1;
    }
 
    /* Testes de Posições*/
    if ((*(*pm)->getListPatient().begin())->getPersonId() != "123456")
    {
        cout << "...verifica_paciente_insere: nao inseriu correctamente o 1º paciente, nao está na posicao correta (ERRO)" << endl;
        er++;
        return er;
    }
    else
        cout << "...verifica_paciente_insere: inseriu o 1º paciente na posicão correta (ok)" << endl;

    if ((*(*pm)->getListPatient().begin())->getVemergency().size() != 2)
    {
        cout << "...verifica_paciente_insere: numero de entradas do 1º Paciente(= "<< (*(*pm)->getListPatient().begin())->getVemergency().size() <<") e' diferente do esperado (=2) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_paciente_insere: numero de entradas do 1º Paciente coincide com o esperado (= 2) (ok)" << endl;    
    
    if ((*(++(*pm)->getListPatient().begin()))->getPersonId() != "108978")
    {
        cout << "...verifica_paciente_insere: nao inseriu correctamente o 2º paciente, nao está na posicao correta (ERRO)" << endl;
        er++;
        return er;
    }
    else
        cout << "...verifica_paciente_insere: inseriu o 2º paciente na posicão correta (ok)" << endl;
    
    return er;
}

int verifica_paciente_remove(PatientManagement **pm)
{
    int er = 0;

    Patient *p;
    
    /*Remoção de Paciente inexistente*/
    p= (*pm)->patientRemove("1234567");

    if (p!=NULL)
    {
        cout << "...verifica_paciente_remove (teste de paciente inexistente): removeu um paciente inexistente (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_paciente_remove (teste de paciente inexistente): nao removeu nenhum Paciente (ok)" << endl;

    p = (*pm)->patientRemove("123456");
    if (!p)
    {
        cout << "...verifica_paciente_remove (teste de paciente valido): nao removeu (ERRO)" << endl;
        er++;
    }
    else if (p->getPersonId() != "123456")
    {
        cout <<"...verifica_paciente_remove (teste de paciente valido): removeu um paciente errado" << p->getPersonId() <<  "(ERRO)" << endl;
        er++;
    }
    else
    {
        cout << "...verifica_paciente_remove (teste de paciente valido): removeu com sucesso (ok)" << endl;
    }

    Patient *p1 = (*pm)->patientRemove("108978");
    if (!p1)
    {
        cout << "...verifica_paciente_remove (teste de paciente valido): nao removeu (ERRO)" << endl;
        er++;
    }
    else if (p1->getPersonId() != "108978")
    {
        cout <<"...verifica_paciente_remove (teste de paciente valido): removeu um paciente errado " << p1->getPersonId() <<  " (ERRO)" << endl;
        er++;
    }
    else
    {
        cout << "...verifica_paciente_remove (teste de paciente valido): removeu com sucesso (ok)" << endl;
    }

    delete p;
    delete p1;
    return er;
}

int verifica_importa(PatientManagement **pm)
{
    int er = 0;
    cout << "A importar PatientManagement..." << endl;

    int  import_ok = (*pm)->import("patients.txt");

    if (import_ok == -1) {
        cout << "...verifica_importa: Erro ao importar base de dados." << endl;
        return 1;
    }
    
    if (*pm == NULL)
    {
        cout << "...verifica_importa: falhou importacao do PatientManagement (ERRO)" << endl;
        return 1;
    }
    else
    {
        if(import_ok == 0) {
        cout << "...verifica_importa: Doentes importados com sucesso." << endl;
        }
        int tam =(*pm)->getListPatient().size();
        if (tam != 50)
        {
            cout << "...verifica_importa: tamanho do PatientManagement "<< tam << " e' diferente do esperado (= 50) (ERRO)" << endl;
            er++;
        }
        else
            cout << "...verifica_importa: tamanho do PatientManagement coincide com o esperado (= 50) (ok)" << endl;
    
    if ((*(*pm)->getListPatient().begin())->getPersonId() != "84707638")
    {
        cout << "...verifica_importa: nao inseriu correctamente o 1º paciente, nao está na posicao correta (ERRO)" << endl;
        er++;
        return er;
    }
    else
        cout << "...verifica_importa: inseriu o 1º paciente na posicão correta (ok)" << endl;

    if ((*(*pm)->getListPatient().begin())->getVemergency().size() != 3)
    {
        cout << "...verifica_importa: numero de entradas do 1º Paciente(= "<< (*(*pm)->getListPatient().begin())->getVemergency().size() <<") e' diferente do esperado (=3) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_importa: numero de entradas do 1º Paciente coincide com o esperado (= 3) (ok)" << endl;    
    }
    return er; 
}

int verifica_getSizeDay(PatientManagement **pm)
{
    int er = 0;
    int idxs;
    tm timeptr{};
    timeptr.tm_year=2023;
    timeptr.tm_mday=28;
    timeptr.tm_mon=2;
    
    idxs = (*pm)->getSizeDay(mktime(&timeptr));

    if (idxs!=25)
    {
        cout << "...verifica_getSizeDay : Total de doentes no dia 28/02/2023: (= "<< idxs <<") e' diferente do esperado (=25) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_getSizeDay : Total de doentes no dia 28/02/2023: "<< idxs<< " (ok)" << endl;
 
    return er;
}


int verifica_searchEmergency(PatientManagement **pm)
{
    int er = 0;
    
    list<Patient *> *idxs = (*pm)->searchEmergency(1);

    if (idxs->size()!=13)
    {
        cout << "...verifica_searchEmergency : Total de doentes com emergência tipo 1: (= "<< idxs->size() <<") e' diferente do esperado (=13) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_searchEmergency : Total de doentes com emergência tipo 1: "<< idxs->size()<< " (ok)" << endl;

    delete idxs;
    return er;
}

int verifica_EmergencyQueues_construtor(EmergencyQueues **eq)
{
    int er = 0;

    *eq = new EmergencyQueues(); 

    if (!(*eq))
    {
        cout << "...verifica_EmergencyQueues_construtor: EmergencyQueues e' NULL (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_EmergencyQueues_construtor: EmergencyQueues nao e' NULL (ok)" << endl;

    return er;
}

int verifica_getPatientsFromList(EmergencyQueues **eq,PatientManagement **pm)
{
    int er = 0;
    cout << "A importar EmergencyQueues..." << endl;
    list<Patient*> lp=(*pm)->getListPatient();
    int  import_ok = (*eq)->getPatientsFromList(lp);

    if (import_ok == -1) {
        cout << "...verifica_getPatientsFromList: Erro ao importar a lista." << endl;
        return 1;
    }
    
    if (*eq == NULL)
    {
        cout << "...verifica_getPatientsFromList: falhou importacao do EmergencyQueues (ERRO)" << endl;
        return 1;
    }
    else
    {
        if(import_ok == 0) {
        cout << "...verifica_getPatientsFromList: Filas criadas com sucesso." << endl;
        }
        int tam =(int)(*eq)->getEmergencyQueues()[0].size();
        if (tam != 9)
        {
            cout << "...verifica_getPatientsFromList: tamanho do fila do tipo de emergencia 0 ("<< tam << ") e' diferente do esperado (= 9) (ERRO)" << endl;
            er++;
        }
        else
            cout << "...verifica_getPatientsFromList:  tamanho do fila do tipo de emergencia 0 coincide com o esperado (= 9) (ok)" << endl;
    
        queue<Patient *> q=(*eq)->getEmergencyQueues()[0];
        Patient *p=q.front();
    
        if (p->getPersonId() != "29522397")
        {
            cout << "...verifica_getPatientsFromList: próximo paciente a ser atendido do tipo de emergencia 0 ("<< p->getPersonId()  << ") e' diferente do esperado (= 29522397) (ERRO)" << endl;
            er++;
            return er;
        }
        else
            cout << "...verifica_getPatientsFromList:  próximo paciente a ser atendido do tipo de emergencia 0 coincide com o esperado (= 29522397) (ok)" << endl;
    }  
    return er; 
}


int verifica_importDischarged(EmergencyQueues **eq)
{
    int er = 0;

    int  import_ok = (*eq)->importDischarged("discharged.txt");

    if (import_ok == -1) {
        cout << "...verifica_importDischarged: Erro ao importar a lista." << endl;
        return 1;
    }
    
    if (*eq == NULL)
    {
        cout << "...verifica_importDischarged: falhou importacao do EmergencyQueues (ERRO)" << endl;
        return 1;
    }
    else
    {
        if(import_ok == 0) {
        cout << "...verifica_importDischarged: Filas atualizadas com sucesso." << endl;
        }
        int tam =(int)(*eq)->getEmergencyQueues()[0].size();
        if (tam != 4)
        {
            cout << "...verifica_importDischarged: tamanho do fila do tipo de emergencia 0 ("<< tam << ") e' diferente do esperado (= 4) (ERRO)" << endl;
            er++;
        }
        else
            cout << "...verifica_importDischarged:  tamanho do fila do tipo de emergencia 0 coincide com o esperado (= 4) (ok)" << endl;
    
        queue<Patient *> q=(*eq)->getEmergencyQueues()[0];
        Patient *p=q.front();
        
            if (p->getPersonId() != "74948019")
            {
                cout << "...verifica_importDischarged: próximo paciente a ser atendido do tipo de emergencia 0 ("<< p->getPersonId()  << ") e' diferente do esperado (= 74948019) (ERRO)" << endl;
                er++;
                return er;
            }
            else
                cout << "...verifica_importDischarged:  próximo paciente a ser atendido do tipo de emergencia 0 coincide com o esperado (= 74948019) (ok)" << endl;
    }

    return er; 
}


int verifica_changeQueue(EmergencyQueues **eq)
{
    int er = 0;

    int  import_ok = (*eq)->changeQueue("74948019",3);

    if (import_ok == -1) {
        cout << "...verifica_changeQueue: Erro ao mudar de fila" << endl;
        return 1;
    }

    if (*eq == NULL)
    {
        cout << "...verifica_changeQueue: falhou mudança de fila(ERRO)" << endl;
        return 1;
    }
    else
    {
        if(import_ok == 0) {
        cout << "...verifica_changeQueue: Filas atualizadas com sucesso." << endl;
        }
        int tam =(int)(*eq)->getEmergencyQueues()[3].size();
        if (tam != 4)
        {
            cout << "...verifica_changeQueue: tamanho do fila do tipo de emergencia 3 ("<< tam << ") e' diferente do esperado (= 4) (ERRO)" << endl;
            er++;
        }
        else
            cout << "...verifica_changeQueue:  tamanho do fila do tipo de emergencia 3 coincide com o esperado (= 4) (ok)" << endl;
    }  
    return er; 
}



int main()
{
    int errorCount = 0, error;

    cout << "INICIO DOS TESTES\n\n" << endl;
    
    /* Verifica construtor do patient */
    Patient *p1;
    error = verifica_patient_construtor(&p1);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_patient_construtor\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_patient_construtor passou\n\n" << endl;
    }  

    /*Verifica setters de paciente */
    error = verifica_patient_setters(&p1);
    if (error)
    {
        cout << "ERRO: " << error << "erros encontrados em verifica_patient_setters\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_patient_setters passou\n\n" << endl;
    }

    /* Verifica addVemergency */
    error = verifica_patient_addVemergency(&p1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_patient_addVemergency\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_patient_addVemergency passou\n\n" << endl;
    }

    /* Verifica addVentrance */
    error = verifica_patient_addVentrance(&p1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_patient_addVentrance\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_patient_addVentrance passou\n\n" << endl;
    }

    /* Verifica construtor do PatientManagement */
    PatientManagement *pm;
    error = verifica_PatientManagement_construtor(&pm);
    if (error)
    {
        cout << "ERRO: " << error << "erros encontrados em verifica_PatientManagement_construtor\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_PatientManagement_construtor passou\n\n" << endl;
    }

    /* Verifica Paciente insere*/ 
    error = verifica_paciente_insere(&pm);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_paciente_insere\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_paciente_insere passou\n\n" << endl;
    }

    /* Verifica componente remove */
    error = verifica_paciente_remove(&pm);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_paciente_remove\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_paciente_remove passou\n\n" << endl;
    }

    /* Verifica importa*/ 
    PatientManagement *pm1 = new PatientManagement;
    error = verifica_importa(&pm1);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_importa\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout<< "OK: verifica_importa passou\n\n" << endl;
    }

    /* Verifica pesquisa categoria */  
    error = verifica_getSizeDay(&pm1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_getSizeDay\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_getSizeDay passou\n\n" << endl;
    }

    error = verifica_searchEmergency(&pm1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_searchEmergency\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_searchEmergency passou\n\n" << endl;
    }

    EmergencyQueues *eq;
 
    error = verifica_EmergencyQueues_construtor(&eq);
    if (error)
    {
        cout << "ERRO: " << error << "erros encontrados em verifica_EmergencyQueues_construtor\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_EmergencyQueues_construtor passou\n\n" << endl;
    }

    error = verifica_getPatientsFromList(&eq,&pm1);
    if (error)
    {
        cout << "ERRO: " << error << "erros encontrados em verifica_getPatientsFromList\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_getPatientsFromList passou\n\n" << endl;
    }

    error = verifica_importDischarged(&eq);
    if (error)
    {
        cout << "ERRO: " << error << "erros encontrados em verifica_importDischarged\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_importDischarged passou\n\n" << endl;
    }

    error = verifica_changeQueue(&eq);
    if (error)
    {
        cout << "ERRO: " << error << "erros encontrados em verifica_changeQueue\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_changeQueue passou\n\n" << endl;
    }

    /* Fim dos testes */
    if (errorCount == 0)
        cout << "FIM DOS TESTES: Todos os testes passaram\n" << endl;
    else
        cout << "FIM DOS TESTES: Foram encontrados "<< errorCount << " ERROS no total\n" << endl;

    delete p1;
    delete pm;
    delete pm1;
    delete eq;

    return 0;
}