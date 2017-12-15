//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Sat Dec  2 03:01:50 PST 2017
// Last Modified: Sat Dec  2 03:01:55 PST 2017
// Filename:      HoleInfo.h
// Web Address:
// Syntax:        C++
// vim:           ts=3:nowrap:ft=text
//
// Description:   Information about holes on piano roll
//

// Compactness: area/perimeter^2
// http://web.cs.wpi.edu/~emmanuel/courses/cs545/S14/slides/lecture08.pdf

#ifndef _HOLEINFO_H
#define _HOLEINFO_H

#include <utility>
#include <iostream>
#include <string>

namespace prp  {

class HoleInfo {
	public:
		         HoleInfo     (void);
		        ~HoleInfo     ();

		std::pair<ulong, ulong>   origin;      // Row, Column of origin (top let corner)
		std::pair<ulong, ulong>   width;       // Row, Column widths.
		std::pair<double, double> centroid;    // Center of mass
		std::pair<ulong, ulong>   entry;       // entry point for filling holes
		ulong                     track;       // tracker hole index
		ulong                     area;        // area of hole
		double                    circularity; // circularity of hole
		double                    perimeter;   // outer contour of hole
		double                    majoraxis;   // angle of longest axis
		double                    coldrift;    // column drive in pixels
		std::string               id;          // unique identifier (if not empty)

		void     clear        (void);
		bool     isMusicHole  (void) { return m_type == 1 ? 1 : 0; }
		void     setNonHole   (void) { m_type = 0; }
		std::ostream& printAton (std::ostream& out = std::cout);

	private:
		char     m_type;
};

std::ostream& operator<<(std::ostream& out, HoleInfo& hi);
std::ostream& operator<<(std::ostream& out, HoleInfo* hi);

} // end prp namespace

#endif /* _HOLEINFO_H */

