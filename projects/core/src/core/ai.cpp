/**
 * @file ai.cpp
 * @author Aleksandr Kohanyuk (shurik_k73@mail.ru)
 * @brief Определение класса ИИ
 */
#include <core/ai.h>

namespace OpenIT {

AI::AI(const Difficulty& difficulty = Difficulty::MEDIUM, const Axis& axis = Axis::X)
  : m_difficulty(difficulty)
  , m_axis(axis)
{
}

void
AI::SetDifficulty(const Difficulty& difficulty)
{
  m_difficulty = difficulty;
}

void
AI::SetAxis(const Axis& axis)
{
  m_axis = axis;
}

Position
AI::Calculate(const Game::Field& field, Position carriage)
{
  /// Скопируем поле
  m_copy_field = field;
  /// Обновляем текущую позицию игрока
  m_current_carrige_pos = carriage;
  /// Сбрасываем лучшую сумму в 0
  /// Устанавливаем кол-во просчёта хода
  m_countItterationdifficulty = static_cast<int8_t>(m_difficulty);
  m_sum                       = 0;
  /// Устанавливаем позициию ИИ
  Position pos_carrige_now = { 0, 0 };
  if (m_axis == Axis::X) {
    pos_carrige_now.x = carriage.x;
  } else {
    pos_carrige_now.y = carriage.y;
  }
  /// Переменная для подсчёта и возврата значения
  int8_t sum = 0;

  for (int8_t i = 0; i < FIELD_SIZE; i++) {
    if (m_axis == Axis::X) {
      pos_carrige_now = { pos_carrige_now.x, i };
    } else {
      pos_carrige_now = { i, pos_carrige_now.y };
    }

    if (m_copy_field[pos_carrige_now.y * FIELD_SIZE + pos_carrige_now.x] != 0) {
      /// Cчитаем значение выбранной ячейки
      sum = 0;
      sum = m_copy_field[pos_carrige_now.y * FIELD_SIZE + pos_carrige_now.x];
      sum = CheckValue(pos_carrige_now, m_countItterationdifficulty, sum, 0);
      /// Обновим лучшую сумму и лучший следующий ход
      if (sum > m_sum) {
        m_sum = sum;
        if (m_axis == Axis::X) {
          m_next_the_best_pos = { pos_carrige_now.x, i };
        } else {
          m_next_the_best_pos = { i, pos_carrige_now.y };
        }
      }
      /// Скопируем поле снова
      m_copy_field = field;
    }
  }
  return m_next_the_best_pos;
}

int8_t
AI::CheckValue(Position carrige, int8_t countItteration, int8_t sum, int8_t bestSum)
{
  /// Ход игрока, перебираем все возможные варинты
  for (int8_t pl = 0; pl < FIELD_SIZE; pl++) {
    /// Выставляем позицию каретки для игрока
    if (m_axis == Axis::X) {
      carrige = { pl, carrige.y };
    } else {
      carrige = { carrige.x, pl };
    }

    /// Если ячейка была не открыта
    if (m_copy_field[carrige.y * FIELD_SIZE + carrige.x] != 0) {
      /// Вычтем разницу между суммой АИ и игрока
      sum = sum - m_copy_field[carrige.y * FIELD_SIZE + carrige.x];
      /// Установим ячейку как открытую
      m_copy_field[carrige.y * FIELD_SIZE + carrige.x] = 0;
    }

    /// Углубляемся
    countItteration--;

    /// Если достигли глубины, то возвращаем значение или больше нет возможности смотреть ходы
    if ((countItteration == 0) || (pl == FIELD_SIZE - 1)) {
      if (bestSum > sum) {
        bestSum = sum;
      }
      return bestSum;
    }

    /// Рассчитываем следующий ход ИИ
    for (int8_t ai = 0; ai < FIELD_SIZE; ai++) {
      /// Выставляем позицию каретки для ИИ
      if (m_axis == Axis::X) {
        carrige = { carrige.x, ai };
      } else {
        carrige = { ai, carrige.y };
      }
      /// Если ячейка была не открыта
      if (m_copy_field[carrige.y * FIELD_SIZE + carrige.x] != 0) {
        /// Прибавим значение к сумме т.к ходит ИИ
        sum = sum + m_copy_field[carrige.y * FIELD_SIZE + carrige.x];
        /// Установим ячейку как открытую
        m_copy_field[carrige.y * FIELD_SIZE + carrige.x] = 0;
        /// Вызовем функцию проверки хода и перезапишем наилучшее значение, когда дойдём до глубины
        bestSum = CheckValue(carrige, countItteration, sum, bestSum);
      }
    }
  }
}

} // namespace OpenIT
