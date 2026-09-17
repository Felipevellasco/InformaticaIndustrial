#include <cstdint>

namespace u {
template <typename T> class vector {
private:
  T *_data;
  uint16_t _allocated;
  uint16_t _used;

  // Método privado para que seja declarado antes do construtor; também permite
  // lógica personalizada com o wrapper público
  void _resize(uint16_t newSize = 0) {
    if (!newSize)
      newSize = ((_allocated + 1) * 3) / 2;

    T *newData = new T[newSize];

    for (uint16_t i = 0; i < _allocated && i < newSize; i++) {
      newData[i] = _data[i];
    }

    delete[] _data;

    _data = newData;
    _allocated = newSize;

    if (newSize < _used)
      _used = newSize;
  }

public:
  vector(uint16_t startSize = 4) : _data(nullptr), _allocated(0), _used(0) {
    if (startSize > 0)
      _resize(startSize);
  }

  vector(vector &) = delete;
  vector(vector &&) = delete;

  ~vector() { delete[] _data; }

  void resize(uint16_t newSize) { _resize(newSize); }

  // Aumenta em 50% se index for menor que o dobro; aumenta em 2*Delta se o
  // index for maior que o dobro O usuário provavelmente vai utilizar mais
  // memória caso ele tenha pedido por mais que o número atual alocado, então é
  // melhor alocar um bloco maior logo de uma vez para impedir múltiplas
  // alocações dinâmicas desnecessárias
  T &operator[](const uint16_t index) {
    if (index >= _allocated) {
      _resize((index < (_allocated * 2)
                   ? (_allocated * 3) / 2
                   : _allocated + 2 * (index - _allocated)));
    }

    if (index + 1 > _used)
      _used = index + 1;

    return _data[index];
  }

  // at() requer excessões para impedir acesso fora do limite do vetor ao mesmo
  // tempo que retorna uma referência T &at(const uint16_t index) {
  //   if (index >= _allocated) {
  //     return nullptr;
  //   }
  //
  //   if (index > _used)
  //     _used = index;
  //
  //   return _data[index];
  // }

  uint16_t size() const { return _used; }
  uint16_t capacity() const { return _allocated; }
};
}; // namespace u
