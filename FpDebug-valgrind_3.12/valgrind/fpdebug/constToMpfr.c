#ifndef _PSCV_
#define _PSCV_
int set_mpfr(ShadowValue *m, double x)
{
   mpfr_t mone, mten, mtwo;
   mpfr_inits2(mpfr_get_prec(m->value), mone, mten, mtwo, (mpfr_ptr)0);
   mpfr_set_d(mone, 1.0, MPFR_RNDN);
   mpfr_set_d(mten, 10.0, MPFR_RNDN);
   mpfr_set_d(mtwo, 2.0, MPFR_RNDN);
   unsigned int *temp;
   temp = &x;
   unsigned int expo = (*(temp + 1) >> 20);
   if (expo < 0x3fc)
   {
      if ((*temp == 0x00000000) && (*(temp + 1) == 0x3c1138ce))
         mpfr_set_d(m->value, 0.0, MPFR_RNDN);
      else if ((*temp == 0x13B13B14) && (*(temp + 1) == 0x3FB3B13B))
      {
         mpfr_div_d(m->value, mone, 13.0, MPFR_RNDN);
      }
      else if ((*temp == 0x1C71C71C) && (*(temp + 1) == 0x3FBC71C7))
      {
         mpfr_div_d(m->value, mone, 9.0, MPFR_RNDN);
      }
      else if ((*temp == 0x745D1746) && (*(temp + 1) == 0x3FB745D1))
      {
         mpfr_div_d(m->value, mone, 11.0, MPFR_RNDN);
      }
      else if ((*temp == 0x55775389) && (*(temp + 1) == 0x3C655555))
      {
         mpfr_set_d(m->value, 7.9999999999999999945604091208046401514e-18, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, -5.7777898331617075591679338277547819556e-34, MPFR_RNDN);
      }
      else if ((*temp == 0x00000000) && (*(temp + 1) == 0x39809d88))
      {
         mpfr_set_d(m->value, 0.0, MPFR_RNDN);
      }
      else if ((*temp == 0x00000000) && (*(temp + 1) == 0x3aa1565d))
      {
         mpfr_set_d(m->value, 0.0, MPFR_RNDN);
      }
      else if ((*temp == 0x1E1E1E1E) && (*(temp + 1) == 0x3FAE1E1E))
      {
         mpfr_div_d(m->value, mone, 17.0, MPFR_RNDN);
      }
      else if ((*temp == 0xBCA1AF28) && (*(temp + 1) == 0x3FAAF286))
      {
         mpfr_div_d(m->value, mone, 19.0, MPFR_RNDN);
      }
      else
      {
         mpfr_set_d(m->value, x, MPFR_RNDN);
         return 0;
      }
   }
   else if (expo < 0x3fe)
   {
      if (((*temp) == 0x55555555) && (*(temp + 1) == 0x3FC55555))
      {
         mpfr_set_d(m->value, 0.16666666666666666, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, 1.2518585419753846e-18, MPFR_RNDN);
      } //special input
      else if (((*temp) == 0x55555A0F) && (*(temp + 1) == 0x3FC55555))
      {
         mpfr_set_d(m->value, 0.16666666666670024, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, -0.36130303910904331133e-18, MPFR_RNDN);
      } //special input 0.16666666666670024
      else if ((*temp == 0xDF3E5244) && (*(temp + 1) == 0x3FC2F112))
      {
         mpfr_set_d(m->value, 1.4798198605116585909999999999999999998e-1, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, -3.0662738607497885838820699497589432422e-20, MPFR_RNDN);
      }
      else if ((*temp == 0xD078C69F) && (*(temp + 1) == 0x3FC39A09))
      {
         mpfr_set_d(m->value, 1.5313837699209373319999999999999999999e-1, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, -1.9846285464882384997040108592588486395e-20, MPFR_RNDN);
      }
      else if ((*temp == 0x96CB03DE) && (*(temp + 1) == 0x3FC74664))
      {
         mpfr_set_d(m->value, 1.8183572161618050120000000000000000008e-1, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, -2.5557009092881344181327226321009203950e-20, MPFR_RNDN);
      }
      else if ((*temp == 0x9997FA04) && (*(temp + 1) == 0x3FD99999))
      {
         mpfr_set_d(m->value, 3.9999999999409419080000000000000000004e-1, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, -2.4966972286347299775383191260379158573e-20, MPFR_RNDN);
      }
      else if ((*temp == 0x94229359) && (*(temp + 1) == 0x3FD24924))
      {
         mpfr_set_d(m->value, 2.8571428743662391490000000000000000006e-1, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, -1.7532829349511302947433670263903954098e-20, MPFR_RNDN);
      }
      else if ((*temp == 0x1D8E78AF) && (*(temp + 1) == 0x3FCC71C5))
      {
         mpfr_set_d(m->value, 2.2222198432149783960000000000000000009e-1, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, -4.2844951413280796167645793459628822189e-20, MPFR_RNDN);
      }
      else if ((*temp == 0x6DC9C883) && (*(temp + 1) == 0x3FD45F30))
      {
         mpfr_const_pi(m->value, MPFR_RNDN);
         mpfr_d_div(m->value, 1.0, m->value, MPFR_RNDN);
      }
      else if ((*temp == 0x1526E50E) && (*(temp + 1) == 0x3FDBCB7B))
      {
         mpfr_set_d(m->value, 4.3429448190325182765112891891660508222e-1, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, 1.0983196502167651099032892174607961931e-17, MPFR_RNDN);
      }
      else if ((*temp == 0x92492492) && (*(temp + 1) == 0x3FC24924))
      {
         mpfr_div_d(m->value, mone, 7.0, MPFR_RNDN);
      }
      else
      {
         mpfr_set_d(m->value, x, MPFR_RNDN);
         return 0;
      }
   }
   else if (expo < 0x400)
   {
      if ((*temp == 0x667f3bcc) && (*(temp + 1) == 0x3ff6a09e)) //sqrt2
      {
         mpfr_set_d(m->value, 1.4142135623730950488016887242096980791, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, -9.6672933134529130371302249634164920441e-17, MPFR_RNDN);
      }
      else if ((*temp == 0x652B82FE) && (*(temp + 1) == 0x3FF71547)) //invln2
      {
         mpfr_set_d(m->value, 1.4426950408889634073599246810018921381, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, 2.0355273740931032050254987870174664842e-17, MPFR_RNDN);
      }
      else if ((*temp == 0x6DC9C883) && (*(temp + 1) == 0x3FE45F30))
      {
         mpfr_const_pi(m->value, MPFR_RNDN);
         mpfr_d_div(m->value, 2.0, m->value, MPFR_RNDN);
      }
      else if ((*temp == 0x55555555) && (*(temp + 1) == 0x3FE55555))
      {
         mpfr_div_d(m->value, mtwo, 3.0, MPFR_RNDN);
      }
      else if ((*temp == 0x50429B6D) && (*(temp + 1) == 0x3FE20DD7))
      {
         mpfr_const_pi(m->value, MPFR_RNDN);
         mpfr_sqrt(m->value, m->value, MPFR_RNDN);
         mpfr_d_div(m->value, 1.0, m->value, MPFR_RNDN);
      }
      else if ((*(temp + 1) == 0x3FE62E42) && (*temp == 0xFEFA39EF)) //ln2
      {
         mpfr_set_d(m->value, 0.69314718055994530941723212145817656831, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, 2.3190468138462996155185846652567995622e-17, MPFR_RNDN);
      }
      else if ((*temp == 0x54442D18) && (*(temp + 1) == 0x3FE921FB))
      {
         mpfr_const_pi(m->value, MPFR_RNDN);
         mpfr_div_d(m->value, m->value, 4.0, MPFR_RNDN);
      }
      else if ((*temp == 0xDC3A03FD) && (*(temp + 1) == 0x3FEEC709))
      {
         mpfr_set_d(m->value, 9.6179669392597560490661645400126142467e-1, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, 5.0577616648125906046872064465284189639e-17, MPFR_RNDN);
      }
      else if ((*temp == 0x13E8135D) && (*(temp + 1) == 0x3FED4F97))
      {
         mpfr_const_catalan(m->value, MPFR_RNDN);
      }
      else if ((*temp == 0xFC6FB619) && (*(temp + 1) == 0x3FE2788C))
      {
         mpfr_const_euler(m->value, MPFR_RNDN);
      }
      else if ((*temp == 0x55555593) && (*(temp + 1) == 0x3FE55555))
      {
         mpfr_set_d(m->value, 6.6666666666667351300000000000000000018e-1, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, -4.1985188465332612218043602932593931142e-20, MPFR_RNDN);
      }
      else if ((*temp == 0x667F3BCD) && (*(temp + 1) == 0x3FE6A09E))
      {
         mpfr_sqrt_ui(m->value, 2, MPFR_RNDN);
         mpfr_div_d(m->value, m->value, 2.0, MPFR_RNDN);
      }
      else
      {
         mpfr_set_d(m->value, x, MPFR_RNDN);
         return 0;
      }
   }
   else if (expo < 0xc00)
   {
      if ((*temp == 0x55555555) && (*(temp + 1) == 0xBFC55555))
      {
         mpfr_set_d(m->value, -1.6666666666666666666666666666666666673e-1, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, -9.2518585385429711702596235994673579379e-18, MPFR_RNDN);
      } // np
      else if ((*temp == 0xBBB55516) && (*(temp + 1) == 0x40026BB1))
      {
         mpfr_set_d(m->value, 2.3025850929940456840179914546843642071, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, -2.1707562233822494506087724117738888026e-16, MPFR_RNDN);
      }
      else if ((*temp == 0x745D1746) && (*(temp + 1) == 0xBFB745D1))
      {
         mpfr_div_d(m->value, mone, 11.0, MPFR_RNDN);
         mpfr_neg(m->value, m->value, MPFR_RNDN);
      }
      else if ((*temp == 0x92492492) && (*(temp + 1) == 0xBFC24924))
      {
         mpfr_div_d(m->value, mone, 7.0, MPFR_RNDN);
         mpfr_neg(m->value, m->value, MPFR_RNDN);
      }
      else if ((*temp == 0x8B145769) && (*(temp + 1) == 0x4005BF0A)) //e
      {
         mpfr_set_d(m->value, 2.7182818284590452353602874713526624979, MPFR_RNDN);
         mpfr_add_d(m->value, m->value, 1.4456468917292501365558887237714884111e-16, MPFR_RNDN);
      }
      else if ((*temp == 0x54442d18) && (*(temp + 1) == 0xbff921fb))
      {
         mpfr_const_pi(m->value, MPFR_RNDN);
         mpfr_div_d(m->value, m->value, 2.0, MPFR_RNDN);
         mpfr_neg(m->value, m->value, MPFR_RNDN);
      }
      else if ((*temp == 0x9999999A) && (*(temp + 1) == 0xBFC99999))
      {
         mpfr_div_d(m->value, mone, 5.0, MPFR_RNDN);
         mpfr_neg(m->value, m->value, MPFR_RNDN);
      }
      else if ((*temp == 0x1C71C71C) && (*(temp + 1) == 0xBFBC71C7))
      {
         mpfr_div_d(m->value, mone, 9.0, MPFR_RNDN);
         mpfr_neg(m->value, m->value, MPFR_RNDN);
      }
      else if ((*temp == 0x13B13B14) && (*(temp + 1) == 0xBFB3B13B))
      {
         mpfr_div_d(m->value, mone, 13.0, MPFR_RNDN);
         mpfr_neg(m->value, m->value, MPFR_RNDN);
      }
      else if ((*temp == 0x1E1E1E1E) && (*(temp + 1) == 0xBFAE1E1E))
      {
         mpfr_div_d(m->value, mone, 17.0, MPFR_RNDN);
         mpfr_neg(m->value, m->value, MPFR_RNDN);
      }
      else if ((*temp == 0xBCA1AF28) && (*(temp + 1) == 0xBFAAF286))
      {
         mpfr_div_d(m->value, mone, 19.0, MPFR_RNDN);
         mpfr_neg(m->value, m->value, MPFR_RNDN);
      }
      else
      {
         mpfr_set_d(m->value, x, MPFR_RNDN);
         return 0;
      }
   }
   else
   {
      mpfr_set_d(m->value, x, MPFR_RNDN);
      return 0;
   }
   return 1;
}

#endif