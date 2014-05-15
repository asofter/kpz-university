using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab5
{
    class AbstractReport
    {
        abstract public void buildHeader();
        abstract public void buildBody();
        abstract public void buildFooter();
    }
}
