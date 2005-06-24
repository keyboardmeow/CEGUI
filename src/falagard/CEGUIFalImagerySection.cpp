/************************************************************************
    filename:   CEGUIFalImagerySection.cpp
    created:    Mon Jun 13 2005
    author:     Paul D Turner <paul@cegui.org.uk>
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://www.cegui.org.uk)
    Copyright (C)2004 - 2005 Paul D Turner (paul@cegui.org.uk)
 
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.
 
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.
 
    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*************************************************************************/
#include "falagard/CEGUIFalImagerySection.h"
#include "CEGUIPropertyHelper.h"

// Start of CEGUI namespace section
namespace CEGUI
{
    ImagerySection::ImagerySection() :
        d_masterColours(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF),
        d_colourProperyIsRect(false)
    {}

    ImagerySection::ImagerySection(const String& name) :
        d_name(name),
        d_masterColours(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF),
        d_colourProperyIsRect(false)
    {}

    void ImagerySection::render(Window& srcWindow, float base_z, const CEGUI::ColourRect* modColours) const
    {
        // decide what to do as far as colours go
        ColourRect finalCols;
        initMasterColourRect(srcWindow, finalCols);

        if (modColours)
            finalCols *= *modColours;

        ColourRect* finalColsPtr = (finalCols.isMonochromatic() && finalCols.d_top_left.getARGB() == 0xFFFFFFFF) ? 0 : &finalCols;

        // render all image components in this section
        for(ImageryList::const_iterator image = d_images.begin(); image != d_images.end(); ++image)
        {
            (*image).render(srcWindow, base_z, finalColsPtr);
        }
        // render all text components in this section
        for(TextList::const_iterator text = d_texts.begin(); text != d_texts.end(); ++text)
        {
            (*text).render(srcWindow, base_z, finalColsPtr);
        }
    }

    void ImagerySection::addImageryComponent(const ImageryComponent& img)
    {
        d_images.push_back(img);
    }

    void ImagerySection::clearImageryComponents()
    {
        d_images.clear();
    }

    void ImagerySection::addTextComponent(const TextComponent& text)
    {
        d_texts.push_back(text);
    }

    void ImagerySection::clearTextComponents()
    {
        d_texts.clear();
    }

    const ColourRect& ImagerySection::getMasterColours() const
    {
        return d_masterColours;
    }

    void ImagerySection::setMasterColours(const ColourRect& cols)
    {
        d_masterColours = cols;
    }

    const String& ImagerySection::getName() const
    {
        return d_name;
    }

    ImagerySection& ImagerySection::operator=(const ImagerySection& other)
    {
        d_name = other.d_name;
        d_masterColours = other.d_masterColours;
        d_images = other.d_images;
        d_texts = other.d_texts;
        d_colourPropertyName = other.d_colourPropertyName;
        d_colourProperyIsRect = other.d_colourProperyIsRect;

		return *this;
    }

    ImagerySection::ImagerySection(const ImagerySection& other)
    {
        d_name = other.d_name;
        d_masterColours = other.d_masterColours;
        d_images = other.d_images;
        d_texts = other.d_texts;
        d_colourPropertyName = other.d_colourPropertyName;
        d_colourProperyIsRect = other.d_colourProperyIsRect;
    }

    void ImagerySection::setMasterColoursPropertySource(const String& property)
    {
        d_colourPropertyName = property;
    }

    void ImagerySection::setMasterColoursPropertyIsColourRect(bool setting)
    {
        d_colourProperyIsRect = setting;
    }

    void ImagerySection::initMasterColourRect(const Window& wnd, ColourRect& cr) const
    {
        // if colours come via a colour property
        if (!d_colourPropertyName.empty())
        {
            // if property accesses a ColourRect
            if (d_colourProperyIsRect)
            {
                cr = PropertyHelper::stringToColourRect(wnd.getProperty(d_colourPropertyName));
            }
            // property accesses a colour
            else
            {
                colour val(PropertyHelper::stringToColour(wnd.getProperty(d_colourPropertyName)));
                cr.d_top_left     = val;
                cr.d_top_right    = val;
                cr.d_bottom_left  = val;
                cr.d_bottom_right = val;
            }
        }
        // use explicit ColourRect.
        else
        {
            cr = d_masterColours;
        }
    }


} // End of  CEGUI namespace section
