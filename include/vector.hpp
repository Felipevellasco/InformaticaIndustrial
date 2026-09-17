#include <cstdint>

namespace u {
template <typename T> class vector {
private:
  T *_data;
  uint32_t _allocated;
  uint32_t _used;

  // Método privado para que seja declarado antes do construtor; também permite
  // lógica personalizada com o wrapper público
  void _resize(uint32_t newSize) {
    T *newData = new T[newSize];

    for (uint32_t i = 0; i < _used && i < newSize; i++) {
      newData[i] = _data[i];
    }

    delete[] _data;

    _data = newData;
    _allocated = newSize;

    if (newSize < _used)
      _used = newSize;
  }

public:
  vector(uint32_t startSize = 4) : _data(nullptr), _allocated(0), _used(0) {
    if (startSize > 0)
      _resize(startSize);
  }

  // Deleta construtores de cópia para impedir vazamento de memória
  vector(const vector &) = delete;
  vector &operator=(const vector &) = delete;
  vector(vector &&) = delete;
  vector &operator=(vector &&) = delete;

  ~vector() { delete[] _data; }

  void resize(uint32_t newSize) { _resize(newSize); }

  // Aumenta em 2x o número de espaços necessários para adicionar o valor no
  // índice pedido pelo usuário; caso o vetor precise crescer, é muito provável
  // que o usuário peça por mais memória posteriormente. Dessa forma,
  // incrementar o vetor em mais espaços que o pedido previne alocações
  // dinâmicas recorrentes, que podem atrasar consideravelmente o código
  // considerando o tamanho do vetor original (que precisa ser copiado).
  T &operator[](const uint32_t index) {
    if (index >= _allocated) {
      uint32_t needed = index + 1;
      uint32_t delta = needed - _allocated;
      uint32_t new_size = _allocated + (2 * delta);
      _resize(new_size);
    }

    if (index + 1 > _used)
      _used = index + 1;

    return _data[index];
  }

  // at() requer excessões para impedir acesso fora do limite do vetor ao mesmo
  // tempo que retorna uma referência T &at(const uint32_t index) {
  //   if (index >= _allocated) {
  //     return nullptr;
  //   }
  //
  //   if (index > _used)
  //     _used = index;
  //
  //   return _data[index];
  // }

  T pop(uint32_t index) {
    T element = _data[index];

    for (int i = index; i < size(); i++) {
      index++;
      _data[i] = _data[index];
    }

    _used--;

    return element;
  }

  uint32_t size() const { return _used; }
  uint32_t capacity() const { return _allocated; }
};
} // namespace u
