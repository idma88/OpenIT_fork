/**
 * @file ai.cpp
 * @author Aleksandr Kohanyuk (shurik_k73@mail.ru)
 * @author Dmitrii Ivanov (idma88@yandex.ru)
 * @brief Определение класса ИИ
 */
#include <optional>

#include <core/ai.h>

namespace OpenIT {

AI::AI(const Difficulty& difficulty, const Axis& axis)
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
AI::Calculate(const Game::Field& field, Position carriage) const
{
  return std::get<1>(MakeMove(field, carriage, m_axis, (uint8_t)m_difficulty * 2));
}

std::tuple<ScoreValue, Position>
AI::MakeMove(Game::Field field, Position carrige, Axis axis, uint8_t steps) const
{
  if (steps == 0) return { 0, carrige };

  std::optional<ScoreValue> bestScore;
  Position                  bestPos;

  Position curPos;
  for (int8_t i = 0; i < FIELD_SIZE; ++i) {
    if (axis == Axis::X)
      curPos = { i, carrige.y };
    else
      curPos = { carrige.x, i };

    int index = curPos.x + curPos.y * FIELD_SIZE;
    if (field[index] == 0) continue;

    Game::Field curField  = field;
    CellValue   cellValue = curField[index];
    curField[index]       = 0;

    std::tuple<ScoreValue, Position> result =
      MakeMove(curField, curPos, (axis == Axis::X ? Axis::Y : Axis::X), steps - 1);

    ScoreValue curScore = cellValue + (axis == m_axis ? -1 : 1) * std::get<0>(result);

    if (!bestScore) {
      bestScore = curScore;
      bestPos   = std::get<1>(result);
    } else if (curScore > bestScore.value()) {
      bestScore = curScore;
      bestPos   = std::get<1>(result);
    }
  };

  return { bestScore.value(), bestPos };
}

} // namespace OpenIT
