#include "parser.hpp"

#include <chrono>
#include <fstream>
#include <iostream>



معيار::المتجه<معيار::المتجه<معيار::المتجه<عدد_صحيح>>> DMX_Parser(معيار::سلسلة اسم_الملف) {
//يجب أن تكون أسماء الوظائف وجميع إخراج النص باللغة الإنجليزية

	معيار::دفق_ملف_الإدخال ملف(اسم_الملف, معيار::الداخل_الخارج_تدفق::الثنائية);
	لو(!ملف.مفتوح()) {
		معيار::ج_خطأ << "Failed to open file: " << اسم_الملف << خط_جديد;
		يعود {};
	}



	اثنان_و_ثلاثون_عدد_صحيح الطابع_الزمني = _٠;
	ثمانية_عدد_صحيح_لم_يتم_توقيعه عرض = _٠;
	ثمانية_عدد_صحيح_لم_يتم_توقيعه الارتفاع = _٠;
	ثمانية_عدد_صحيح_لم_يتم_توقيعه عمق = _٠;

	ملف.يقرأ(إعادة_التفسير_صب<حرف*>(&الطابع_الزمني), حجم(الطابع_الزمني));
	ملف.يقرأ(إعادة_التفسير_صب<حرف*>(&عرض), حجم(عرض));
	ملف.يقرأ(إعادة_التفسير_صب<حرف*>(&الارتفاع), حجم(الارتفاع));
	ملف.يقرأ(إعادة_التفسير_صب<حرف*>(&عمق), حجم(عمق));



	حرف المخزن_المؤقت[_٨*_٧+_١+_١];		//أكبر بحرف واحد ، للسماح بإنهاء صفر
	ملف.يقرأ(المخزن_المؤقت, _٨*_٧+_١);	//قراءة الحقل بأكمله
	المخزن_المؤقت[_٨*_٧+_١] = باطل_حرف;	//مضيفا إنهاء صفر
	معيار::سلسلة اسم_الخالق(المخزن_المؤقت);



	معيار::ج_خارج << "Time creation Unix timestamp: "
	<< الطابع_الزمني
	<< خط_جديد << "Name of file creator: "
	<< اسم_الخالق << خط_جديد;



	معيار::المتجه<معيار::المتجه<معيار::المتجه<عدد_صحيح>>> مصفوفة_للعودة(
		عمق,
		معيار::المتجه<معيار::المتجه<عدد_صحيح>>(
			الارتفاع,
			معيار::المتجه<عدد_صحيح>(
				عرض,
				_٠
			)
		)
	);

	خلال(نوع_الحجم شريحة = _٠; شريحة < عمق; شريحة++) {
		خلال(نوع_الحجم صف = _٠; صف < الارتفاع; صف++) {
			خلال(نوع_الحجم عمود = _٠; عمود < عرض; عمود++) {
				اثنان_و_ثلاثون_عدد_صحيح__لم_يتم_توقيعه لإضافة = _٠;
				ملف.يقرأ(إعادة_التفسير_صب<حرف*>(&لإضافة), حجم(لإضافة));
				مصفوفة_للعودة[شريحة][صف][عمود] = لإضافة;
			}
		}
	}



	ملف.غلق();

	يعود مصفوفة_للعودة;
}
