#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <ostream>

namespace Solatire
{
	namespace Engine
	{
		enum class Suit
		{
			Hearts = 0,
			Diamonds,
			Clubs,
			Spades,
			First = Hearts,
			Last = Spades
		};

		std::string to_string(Suit suit)
		{
			switch(suit)
			{
				case Suit::Hearts:
					return "H";
				case Suit::Diamonds:
					return "D";
				case Suit::Clubs:
					return "C";
				case Suit::Spades:
					return "S";
				default:
					throw std::out_of_range("Suit is out of range.");
			}
		}

		std::ostream& operator<<(std::ostream &stream, Suit suit)
		{
			return (stream << to_string(suit));
		}

		enum class Rank
		{
			Two = 2,
			Three,
			Four,
			Five,
			Six,
			Seven,
			Eight,
			Nine,
			Ten,
			Jack,
			Queen,
			King,
			Ace
		};

		std::string to_string(Rank rank)
		{
			switch(rank)
			{
				case Rank::Two:
					return "2";
				case Rank::Three:
					return "3";
				case Rank::Four:
					return "4";
				case Rank::Five:
					return "5";
				case Rank::Six:
					return "6";
				case Rank::Seven:
					return "7";
				case Rank::Eight:
					return "8";
				case Rank::Nine:
					return "9";
				case Rank::Ten:
					return "10";
				case Rank::Jack:
					return "J";
				case Rank::Queen:
					return "Q";
				case Rank::King:
					return "K";
				case Rank::Ace:
					return "A";
				default:
					throw std::out_of_range("Rank is out of range.");
			}
		}

		std::ostream& operator<<(std::ostream &stream, Rank rank)
		{
			return (stream << to_string(rank));
		}

		class Card
		{
		private:
			int _number;
		public:
			Card(int number);
			int get_number() const;
			Suit get_suit() const;
			Rank get_rank() const;
			bool get_black() const;
	
		};

		Card::Card(int number) : _number(number)
		{
		}

		int Card::get_number() const
		{
			return _number;
		}

		Suit Card::get_suit() const
		{
			return static_cast<Suit>(_number / 13);
		}

		Rank Card::get_rank() const
		{
			return static_cast<Rank>(_number % 13 + 2);
		}

		bool Card::get_black() const
		{
			Suit suit = get_suit();
			return suit == Suit::Clubs || suit == Suit::Spades;
		}
	}
}

#endif
