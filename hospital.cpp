#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <sstream>
#include <list>
#include <chrono>
#include <iomanip>
#include <queue>
#include "hospital.hpp"

using namespace std;
Patient::Patient(string personId, string name)
{
  this->personId = personId;
  this->name = name;
  this->discharged = false;
}

Patient::Patient(string personId, string name, string patientId, time_t birthDate, char sex, short int emergency, time_t ymd)
{
  this->personId = personId;
  this->name = name;
  this->patientId = patientId;
  this->birthDate = birthDate;
  this->sex = sex;
  this->vemergency.clear();
  this->vemergency.push_back(emergency);
  this->ventrance.clear();
  this->ventrance.push_back(ymd);
  this->discharged = false;
}

string Patient::getPersonId() const
{
  return this->personId;
}

string Patient::getName() const
{
  return this->name;
}

string Patient::getPatientId() const
{
  return this->patientId;
}

time_t Patient::getBirthDate() const
{
  return this->birthDate;
}

char Patient::getSex() const
{
  return this->sex;
}

bool Patient::getDischarged() const
{
  return this->discharged;
}

vector<short int> Patient::getVemergency() const
{ 
  return this->vemergency;
}

vector<time_t> Patient::getVentrance() const
{
  return this->ventrance;
}

void Patient::setName(string name)
{
  // verificar se o valor é valido seria o que existe
  if(!name.empty()){
    this->name = name;
  }
}

void Patient::setPatientId(string patientId)
{
  //Verdifique que os valores e valido seria se ele exestir
   if(!patientId.empty()){
    this->patientId = patientId;
  }
}

void Patient::setBirthDate(time_t birthDate)
{
  //verfique que os valores e valido seria q ele existe
  if(birthDate != 0){
    this->birthDate = birthDate;
  }
}

void Patient::setSex(char sex)
{
  //Verifique que os valores e valido seria q eles existem
  if(sex != 'M' || sex != 'F'){
    this->sex = sex;
  }
}

void Patient::setDischarged(bool discharged)
{
  //Verifique que os valores e valido seria q eles existem
  if(discharged != false){
    this->discharged=true;
  }

}

void Patient::addVentrance(time_t ymd)
{
  //Acresentar o vator ventrace q seria as entradas do doente
  ventrance.push_back(ymd);
}

void Patient::addVemergency(short int emergency)
{ 
  //Acresenta o vetor venmergy q seria o tipo de userncia
  vemergency.push_back(emergency);
}

PatientManagement::PatientManagement()
{
  //Construtor. Cria um objeto da classe PatientManagement, garantindo que a lista listPatient se enconta vazia
  listPatient.clear();
}

PatientManagement::~PatientManagement()
{
  //apagar com o delet ao patiente depois fazer erase ao elemento da lista de patiente
  //for(auto it=listPatient.begin();it!=listPatient.end();it++){}

}

list<Patient *> PatientManagement::getListPatient() const
{
 return listPatient;
}

size_t PatientManagement::getSize() const
{
  return listPatient.size();
}

int PatientManagement::getSizeDay(time_t ymd) const
{
  int comparacao;
  for(auto auxi = listPatient.begin();auxi!=listPatient.end();auxi++){
    for(auto it = (*auxi)->getVentrance().begin();it!=(*auxi)->getVentrance().end();it++){
      if(*it==ymd){//Esse argumento não esta certo
        comparacao++;
        break;
      }
      else{
        return -1;
      }
    }
  }
  return comparacao/2;
}

int PatientManagement::patientInsert(Patient *p)
{
  /*
  // Este codigo é do chat gpt
 // This function returns a boolean to indicate whether the patient was inserted or not
    bool patientExists = false; // Flag indicating whether the patient already exists
    string patientId = p->getPatientId(); // Get the patient ID from the new patient object
    Patient* existingPatient = nullptr; // Pointer to the existing patient object (if any)

    // Search for the patient in the list of patients
    for (auto i = listPatient.begin(); i != listPatient.end(); i++) {
        if (patientId == (*i)->getPatientId()) {
            patientExists = true;
            existingPatient = (*i); // Keep a pointer to the existing patient object
            break;
        }
    }

    // If the patient already exists, update its information
    if (patientExists) {
        // Get the emergency contact and entrance date from the new patient object
        auto emergencyContact = p->getVemergency()[0];
        auto entranceDate = p->getVentrance()[0];

        // Update the existing patient object with the new information
        existingPatient->addVemergency(emergencyContact);
        existingPatient->addVentrance(entranceDate);
        //existingPatient->updatePatientInfo(p);

        // Delete the new patient object, since we no longer need it
        delete p;

        // Return true to indicate that the patient was updated
        return true;
    }
    else {
        // Add the new patient object to the list
        listPatient.push_back(p);

        // Return false to indicate that the patient was inserted
        return false;
    }
    */
// código tava dando errado

bool exite; // bool da exixtencia de u  igual ou n
  string perid; //variavel auxiliar
  perid = p->getPatientId();
  Patient *j= NULL; // guarda apontadador se este exitir  
  for ( auto i = listPatient.begin();i != listPatient.end();i++)
    {
      //procura e compara o personid dentro do vetor de apontadores 
      if (perid == (*i)->getPatientId())
      {
        j=*i;
        exite = true;
        break;
      }
    }
  if (exite){
    //adiciona o valor criado a um vetor exitente existentes
    auto kem = p->getVemergency();
    (j)->addVemergency(kem[0]);
    auto ken = p->getVentrance();  
    (j)->addVentrance(ken[0]);
    // remove o criado (temporariamente) depois de atualizar o que exite
    delete p;
     
    // atualizar as informações do paciente e tem que apagar ele pois vai ter ele novamente e assim ser um memori leak
    return 1;
  }
  else
  {
    listPatient.push_back(p);
    // nao exieste acresetno patiente;
    return 0;
  }
return -1;

}

Patient *PatientManagement::patientRemove(const string id)
{
  
    Patient *lostPointer;
    for (auto i = listPatient.begin(); i != listPatient.end(); i++)
    {
        if ((*i)->getPersonId() == id)
        {
            lostPointer = *i;
            getListPatient().erase(i);
            return lostPointer;
        }
        }

        return NULL;
}


int PatientManagement::import(const string name_file)
{
  if (name_file.empty())
  {
    return -1;
  }
  ifstream f(name_file);
  if (!f)
  {
    return -1;
  }
  string PersonId, name, PatientId;
  int emergency;
  char sex;
  time_t ymd, birth;
  Patient *p;
  int result;
  string s;
  stringstream ss, ssd;
  char delim = ',';
  tm *timeptr = new tm{};
  string date_time_format = "%m/%d/%Y";

  while (getline(f, s)) {
    ss.clear();
    ss << s;
    getline(ss, PersonId, delim);
    getline(ss, name, delim);
    getline(ss, s, delim);
    sex = s[0];
    
    getline(ss, s, delim);
    ssd.clear();
    ssd << s;
    getline(ssd, s, '/');
    timeptr->tm_mday = stoi(s);
    getline(ssd, s, '/');
    timeptr->tm_mon = stoi(s);
    getline(ssd, s, ' ');
    timeptr->tm_year = stoi(s);
    birth = mktime(timeptr);

    getline(ss, PatientId, delim);
    
    getline(ss, s, delim);
    emergency = stoi(s);

    getline(ss, s, delim);
    ssd.clear();
    ssd << s;
    getline(ssd, s, '/');
    timeptr->tm_mday = stoi(s);
    getline(ssd, s, '/');
    timeptr->tm_mon = stoi(s);
    getline(ssd, s, ' ');
    timeptr->tm_year = stoi(s);
    ymd = mktime(timeptr);

    p = new Patient(PersonId, name, PatientId, birth, sex, emergency, ymd);

    if (!p) {
      delete p;
      f.close();
      return -1;
    }

    result = patientInsert(p);
    if (result == -1) {
      delete p;
      f.close();
      return -1;
    }
  }

  f.close();
  delete timeptr;
  return 0;
}

list<Patient *> *PatientManagement::searchEmergency(short int emergency)
{
/*
  //for (auto i = vqueueEmergency.begin();i != vqueueEmergency.end();i++)
  //{
  list<Patient *> newPatientList;
  vector <short int > temporaryPatientEmergencies;
  short int lastTemporaryPatientEmergency;
  for (auto i = listPatient.begin(); i != listPatient.end(); i++)
  {
    if(!(*i)->getDischarged())
    {
      temporaryPatientEmergencies = (*i)->getVemergency();
      lastTemporaryPatientEmergency = *(temporaryPatientEmergencies.end());
      if(emergency == lastTemporaryPatientEmergency)
      {
        newPatientList.push_back((*i));
      }
    }
    */
  }
  //}
    // procurar todos os paciente para um determinado tipo de emergency, ou seja e para descobrir todos que estao la em algum tipo de emergia, 
    // corre a lista tudo e em cada um dele 1 coisa a ver e se ele já tiver alta, se tiver passa a frente, se não tiver alta ver o vetor emergencia ver o ultimo etipo de emergia e se for igual acresenta o pacinete em uma nova lista
    return NULL;
}
EmergencyQueues::EmergencyQueues()
{
  vqueueEmergency.clear();
    for (auto i =vqueueEmergency.begin(); i!=vqueueEmergency.end();i++)
    {
      if((*i).empty())
        i++;
      else
        for(auto j =(*i).front();j != (*i).back();j++)
        {
          (*i).pop();
        }

    }
  //esse tipo de varivel é uma fila que tem o tipo de doençar cada um com sua fila e paciente, por ordem de chegada
}

vector<queue<Patient *>> EmergencyQueues::getEmergencyQueues() const
{
  //Busca esse vetor
}

size_t EmergencyQueues::getSize(short int emergency) const
{
  //Ver o tamanho de uma determinad fila
    if (emergency >= 5)
    {
      return NULL;
    }
    else
    {
      auto &currentQueue = vqueueEmergency[emergency];
      return currentQueue.size();
    }
}

int EmergencyQueues::patientInsert(Patient *p)
{
  auto currentEmergency = p->getVemergency().end();
    vqueueEmergency[p->getVemergency().end()] = p;

    for (auto i = vqueueEmergency.begin(); i != vqueueEmergency.end(); i++)
    {
        if (*i== *currentEmergency)
        {
          (*i).push(p);
          return 1;
        }
    }
    // temos o paciente e vamos inserir na fila na funçao(emergyqueues) para inserir ver a ultima posição do vetor emergia e de acordo colocar ele na fila
    return 0;
}

Patient *EmergencyQueues::patientRemove(short int emergency)
{
  //
  return NULL;
}

int EmergencyQueues::getPatientsFromList(list<Patient *> listPatient)
{
  //e ir buscar a nossa lista e preencher atraves da nossa lista preencher as nossas filas 1 a 1 ir ao paciente ver se ele tem alta, não tem alta ver qual e o ultimo tipo de memencia
  return 0;
}

int EmergencyQueues::importDischarged(const string name_file)
{
  //temos m fichero de texto que em cada linha tem dois numero 1 numero disz qual e a emergia e o 2 diz quantos pessoas tiveram alta em cada emercencia
  return 0;
}

int EmergencyQueues::changeQueue(const string id, short int new_E)
{
  //e mudar o paciente de uma fila para outro, tipo ele ja ta dentro com tipo 1 de emercencia e ele piora e vai para o tipo 3 de emrcia, ou seja tem que muda ele de fila
  // a questao e como ele q procura uma coisa na fila e remover ele
  // para remover um cara q testa no meio ver um e colocar ele denovo na mesma fila ate encontra o cara que vai esta na posição 1 da fila e depois fazer um pop, depois de remover e so acresentar na nova fila
  return 0;
}
