/**
 * @file aialgorithm.h
 * @author Dmitrii Ivanov (idma88@yandex.ru)
 * @brief Определение класса Игрок
 */
#pragma once

#include <cstdint>
#include <vector>

#include <core/common.h>

namespace OpenIT {
/**
 * @brief AI
 */
class AI
{
public:
  /**
   * @brief Конструктор
   *
   */
  AI(const LEVEL& level = LEVEL::EASY, const AXIS& axis = AXIS::X);

  /**
   * @brief Деструктор
   */
  ~AI() = default;

  /**
   * @brief Устанавливает уровень сложности
   *
   * @param[in] level уровень сложности
   */
  void SetDifficultyLevel(const LEVEL& level);

  /**
   * @brief Устанавливает по какой оси будет двигаться каретка
   *
   * * @param[in] axis ось по которой передвигается каретка AI
   */
  void SetAXIS(const AXIS& axis);

private:
  /**
   * @brief
   *
   * * @param[in]
   */
  int8_t CheckValue(Position carrige, int8_t countItteration, int8_t sum, int8_t bestSum);
  /**
   * @brief Рассчитывает ход
   *
   *  @param[in] field уровень сложности
   *
   * @return Возвращает true в случае успеха или false в противном случае
   */
  Position Calculate(const std::vector<int>& field, Position posPlayer);

private:
  /// Уровень сложности бота
  LEVEL m_level = LEVEL::EASY;
  /// Ось по которой двигается каретка
  AXIS m_axis = AXIS::X;
  /// Лучшая сумма за все ходы
  int8_t m_sum;
  /// Текущая позиция игрока
  Position m_current_carrige_pos;
  /// Лучший следующий ход
  Position m_next_the_best_pos;
  /// Размер поля в ширину
  const int8_t WIDTH = 8;
  /// Размер поля в высоту
  const int8_t HEIGHT = 8;
  /// Кол-во просмотренных ходов ИИ
  int8_t m_countItterationLevel = 0;
  /// Копия поля
  std::vector<int> m_copy_field;
};
} // namespace OpenIT