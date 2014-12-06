/*
 * Project Euler #17 by Josh Oldenburg, 12/6/2014
 *
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
 */

import Cocoa

var count: Int = 0
let formatter = NSNumberFormatter()
formatter.numberStyle = .SpellOutStyle
formatter.locale = NSLocale(localeIdentifier: "en_GB")

let badCharacters = NSCharacterSet(charactersInString: "- ,")

for i in 1...1000 {
	let components = formatter.stringFromNumber(i)!.componentsSeparatedByCharactersInSet(badCharacters)
	let joined = "".join(components)

	var length = countElements(joined)
	if i > 100 && i % 100 != 0 {
		length += 3
	}
	count += length;
}

print("\(count)")
