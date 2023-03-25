#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <list>
#include <queue>

using namespace std;

class Patient {
    private:
        /* ATRIBUTOS
        *   personId     - identificação única do doente
        *   name         - nome do doente
        *   birth_date   - data de nascimento do doente
        *   patientId    - número de utente
        *   sex          - M | F (Masculino | Feminino)
        *   discharged   - alta (true se já teve alta | false se ainda não teve alta)
        *   vemergency   - vetor com os tipos de emergência de cada entrada
        *                      > 0 - azul (não urgente)
        *                      > 1 - verde (pouco urgente)
        *                      > 2 - amarelo (urgente)
        *                      > 3 - laranja (muito urgente)
        *                      > 4 - vermelho (emergência absoluta)
        *   ventrance    - vetor com os dias em que deu entrada
        */
        string personId, name, patientId ;
        time_t birthDate;
        char sex; 
        bool discharged;
        vector <short int> vemergency;
        vector<time_t> ventrance;
    public:
        /* MÉTODOS */
        
        // Constructors

        /** 
         *  @brief Construtor (parametrizado)
         *  @param personId identificação do doente
         *  @param name nome do doente
         *  @note  Inicializa os atributos com o correspondente argumento, 'discharged' a false e resto a 0 ou "".
         */
        Patient(string personId, string name);

        /** 
         *  @brief Constructor (parametrizado)
         *  @param personId identificação do doente
         *  @param name nome do doente
         *  @param patientId número de utente do doente
         *  @param birthDate data de nascimento do doente
         *  @param sex tipo de sexo do doente
         *  @param emergency tipo de emergência
         *  @param ymd data de entrada na urgência
         *  @note  Inicializa os atributos com o correspondente argumento e 'discharged' a false.
         */
        Patient(string personId, string name, string patientId, time_t birthDate, char sex, short int emergency, time_t ymd);
        
        // Get Methods

        /** 
         *  @brief  Obter a identificação do doente.
         *  @param  none
         *  @return 'personId' do 'Patient'
         */
        string getPersonId() const;

        /** 
         *  @brief  Obter o nome do doente.
         *  @param  none
         *  @return 'name' do 'Patient'
         */
        string getName() const;

        /** 
         *  @brief  Obter o número de utente do doente.
         *  @param  none
         *  @return 'patientId' do 'Patient'
         */
        string getPatientId() const;

        /** 
         *  @brief  Obter a data de nascimento do doente.
         *  @param  none
         *  @return 'birthDate' do 'Patient'
         */
        time_t getBirthDate() const;

        /** 
         *  @brief  Obter o tipo de sexo do doente.
         *  @param  none
         *  @return 'sex' do 'Patient'
         */
        char getSex() const;

        /** 
         *  @brief  Obter a alta do doente.
         *  @param  none
         *  @return 'discharged' do 'Patient'
         */
        bool getDischarged() const;

        /** 
         *  @brief  Obter o vetor com os tipos de urgência do doente.
         *  @param  none
         *  @return 'vemergency' do 'Patient'
         */
        vector<short int> getVemergency() const;

        /** 
         *  @brief  Obter o vetor de entradas na urgência do doente.
         *  @param  none
         *  @return 'ventrance' do 'Patient'
         */
        vector<time_t> getVentrance() const;

        // Set Methods

        /** 
         *  @brief  Definir o nome do doente.
         *  @param  name 'name' do 'Patient'
         *  @return void
         */
        void setName(string name);

        /** 
         *  @brief  Definir o número de utente do doente.
         *  @param  patientId 'patientId' do 'Patient'
         *  @return void
         */
        void setPatientId(string patientId);

        /** 
         *  @brief  Definir a data de nascimento do doente.
         *  @param  birthDate 'birthDate' do 'Patient'
         *  @return void
         */
        void setBirthDate(time_t birthDate);
        
        /** 
         *  @brief  Definir o tipo de sexo do doente.
         *  @param  sex 'sex' do 'Patient'
         *  @return void
         */
        void setSex(char sex);

        /** 
         *  @brief  Definir o estado (true/false) da alta do doente.
         *  @param  discharged 'discharged' do 'Patient'
         *  @return void
         */
        void setDischarged(bool discharged);

        // Other Methods

        /** 
         *  @brief  Adicionar ao vetor uma nova entrada (datas) do doente.
         *  @param  ymd novo elemento (data do tipo chrono::year_month_da) a inserir em 'ventrance'
         *  @return void
         */
        void addVentrance(time_t ymd);

        /** 
         *  @brief  Adicionar ao vetor uma nova entrada (tipo de emergência) do doente.
         *  @param  emergency novo elemento a inserir em 'vemergency'
         *  @return void
         */
        void addVemergency(short int emergency);

};

class PatientManagement {
    private:
        /* ATRIBUTOS 
         *   listPatient    - lista de apontadores para os doentes (apontadores para objetos da classe Patient)
         */
        list<Patient*> listPatient;
    public:
        /* MÉTODOS */

        // Constructor and Destructor 

        /** 
         *  @brief Construtor default
         *  @note  Garante que a lista 'listPatient' está vazia.
         */
        PatientManagement();

        /** 
         *  @brief Destrutor
         *  @note  Apaga em memória os objetos da classe 'Patient'.
         */
        ~PatientManagement();

        // Get Methods

        /** 
         *  @brief  Obter a lista de doentes da base de dados.
         *  @param  none
         *  @return 'listPatient'
         */
        list<Patient*> getListPatient() const;

        // Other Methods

        /** 
         *  @brief  Obter o número de doentes da base de dados.
         *  @param  none
         *  @return número total de doentes
         */
        size_t getSize() const;

        /** 
         *  @brief  Obter o número de doentes que recorreram à urgência em determinado dia.
         *  @param  ymd dia (data)
         *  @return número de doentes | -1 se ocorreu um erro
         */
        int getSizeDay(time_t ymd) const;

        /** 
         *  @brief  Inserir um doente no final da lista.
         *  @param  p doente ('Patient') a inserir
         *  @return 0 se o doente não existia e foi inserido com sucesso |
         *  @return 1 se o doente já existia na lista e apenas foi atualizado |
         *  @return -1 se ocorrer um erro
         *  @note   Caso o doente já exista (tenha o mesmo 'personId'), adicionar apenas a nova data e respetivo tipo
         *          de emergência na última posição do vetor 'ventrance' e 'vemergency', respetivamente.
         */
        int patientInsert(Patient *p);

        /** 
         *  @brief  Remover da lista um doente pela sua identificação.
         *  @param  id 'personId' do doente a remover
         *  @return apontador para o doente ('Patient') removido |
         *  @return NULL se ocorrer um erro ou o doente não existir na lista
         */
        Patient* patientRemove(const string id);

        /** 
         *  @brief  Preencher a base de dados (lista), lendo o conteúdo de um ficheiro de texto.
         *  @param  nameFile nome do ficheiro de texto contendo a lista de doentes a importar
         *  @return 0 em caso de sucesso | -1 se ocorrer um erro
         *  @note   Cada linha do ficheiro corresponde a uma entrada de um doente e tem o seguinte formato:
         *          personId,name,sex,birthDate,patientId,emergency,emergency_date
         */
        int import(const string nameFile);

        /** 
         *  @brief  Pesquisar todos os doentes que tenham determinado tipo de emergência.
         *  @param  emergency tipo de emergência a procurar
         *  @return apontador para uma lista de apontadores com os doentes ('Patient') encontrados | NULL se ocorrer um erro
         */
        list<Patient*>* searchEmergency(short int emergency);

};

class EmergencyQueues {
    private:
        /* ATRIBUTOS 
        *   vqueueEmergency    - vetor de filas de doentes (apontadores para objetos da classe Patient)
        *                        (cada posição corresponde a uma fila associada a um tipo de emergência)
        *                              > 0 - azul
        *                              > 1 - verde
        *                              > 2 - amarelo
        *                              > 3 - laranja
        *                              > 4 - vermelho
        */
        vector<queue<Patient*>> vqueueEmergency;
    public:
        /* MÉTODOS */

        // Constructor and Destructor 

        /** 
         *  @brief Construtor default
         *  @note  Garante que o vetor 'vqueueEmergency' criou as 5 filas vazias.
         */
        EmergencyQueues();

        // Get Methods
        
        /** 
         *  @brief  Obter o vetor de filas de emergência.
         *  @param  none
         *  @return 'vqueueEmergency'
         */
        vector<queue<Patient*>> getEmergencyQueues() const;

        // Other Methods

        /** 
         *  @brief  Obter o número de doentes existente em determinada fila de emergência.
         *  @param  emergency tipo de emergência (posição da fila a procurar)
         *  @return número total de doentes na fila
         */
        size_t getSize(short int emergency) const;

        /** 
         *  @brief  Inserir um doente na fila de emergência correspondente à sua última entrada na urgência.
         *  @param  p doente ('Patient') a inserir
         *  @return 0 se o doente foi inserido com sucesso | -1 se ocorrer um erro
         */
        int patientInsert(Patient *p);

        /** 
         *  @brief  Remover um doente da fila correspondente ao tipo de emergência.
         *  @param  emergency tipo de emergência
         *  @return apontador para o doente ('Patient') removido |
         *  @return NULL se ocorrer um erro ou se a fila estiver vazia
         *  @note   O estado da alta do doente a remove dever ser atualizado para 'true'.
         */
        Patient* patientRemove(short int emergency);

        /** 
         *  @brief  Preencher as filas de emergência com a informação da lista de doentes.
         *  @param  listPatient lista de doentes (base de dados)
         *  @return 0 em caso de sucesso | -1 se ocorrer um erro
         */
        int getPatientsFromList(list<Patient*> listPatient);

        /** 
         *  @brief  Atribuir alta aos doentes em cada fila de emergência, lendo o conteúdo de um ficheiro de texto.
         *  @param  nameFile nome do ficheiro de texto
         *  @return 0 em caso de sucesso | -1 se ocorrer um erro
         *  @note   Cada linha do ficheiro contém dois números separados por uma vírgula.
         *          O primeiro é o tipo de emergência e o segundo é o número de doentes que tiveram alta.
         */
        int importDischarged(const string nameFile);

        /** 
         *  @brief  Transferir um doente de fila de emergência.
         *  @param  id 'personId' do doente
         *  @param  newE novo tipo de emergência do doente
         *  @return 0 em caso de sucesso | -1 se ocorrer um erro
         *  @note   No caso de, em determinada urgência, o tipo de emergência do doente se alterar, é necessário alterá-lo
         *          para uma nova fila de emergência e atualizar o tipo de emergência do objeto correspondente.
         */
        int changeQueue(const string id, short int newE);
        
};

#endif