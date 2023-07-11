#include "Serializer.hpp"


/* WIKIPEDIA: serialização

    Em ciência da computação, no contexto de armazenamento 
        e transmissão de dados, serialização é o processo de 
        tradução de estruturas de dados ou estado de objeto em
        um formato que possa ser armazenado (por exemplo, em 
        um arquivo ou buffer de memória, ou transmitido por 
        meio de um enlace de conexão de rede) e reconstruído 
        posteriormente no mesmo ou em outro ambiente computacional.
        Quando a série de bits resultante é relida de acordo com o 
        formato de serialização, ela pode ser usada para criar um 
        clone do objeto original idêntico semanticamente. Para muitos 
        objetos complexos, como aqueles que fazem uso extensivo de 
        referências, este processo não é direto. A serialização de 
        objetos orientados a objetos não incluem qualquer de seus 
        métodos associados com os quais eles foram previamente ligados 
        inextricavelmente.
*/


int main(void)
{
    Data* data = new Data();
    data->setS1("Isto");
    data->setS2("Aquilo");
    data->setN(42);

    uintptr_t raw = Serializer::serialize(data);
    std::cout << raw << std::endl;

    Data* data2 = Serializer::deserialize(raw);

    std::cout << data2->getS1() << std::endl;
    std::cout << data2->getN() << std::endl;
    std::cout << data2->getS2() << std::endl;

    delete data;
    return 0;
}