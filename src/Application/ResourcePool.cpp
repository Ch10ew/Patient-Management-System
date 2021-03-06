#include "ResourcePool.h"

#include "../Structures/List.h"
#include "../Structures/Nurse.h"
#include "../Structures/Doctor.h"
#include "../Structures/Patient.h"
#include "../Structures/CtimeWrapper.h"

#include <memory>
#include <string>

namespace pms
{
    ResourcePool::ResourcePool()
    {
        // Hardcoded Nurse data
        nurse_data.InsertTail(std::make_shared<Nurse>(
            "N0001",
            "faizal",
            "faizal123",
            "Faizal bin Abdullah",
            ""
        ));
        
        // Hardcoded Doctor data
        doctor_data.InsertTail(std::make_shared<Doctor>(
            "D0001",
            "hafiz",
            "hafiz123",
            "Hafiz bin Abdul",
            "",
            "Optometry"
        ));

        doctor_data.InsertTail(std::make_shared<Doctor>(
            "D0002",
            "tan",
            "tan",
            "Chee Ming",
            "Tan",
            "Optometry"
        ));

        // Hardcoded Patient data
        // 1
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000001",
            "John",
            "Smith",
            21,
            'M',
            "019-6103755",
            "1, Jalan 2, Taman 3, 52200, Kuala Lumpur",
            "",
            5
        ));

        // 2
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000002",
            "Kris",
            "Wu",
            30,
            'M',
            "012-9876543",
            "2, Jalan 3, Taman 4, 52200, Kuala Lumpur",
            "",
            5
        ));

        // 3
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000003",
            "Monica",
            "Cheng",
            20,
            'F',
            "012-3456789",
            "69, Jalan 30CM, Taman Kacang Deez, 47100 Puchong, Selangor",
            "",
            5
        ));

        // 4
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000004",
            "Madelline",
            "Ping",
            87,
            'F',
            "011-27273656",
            "12, Jalan Elitis Pinggu, Taman Gay, Sugahati, 41900, Selangor",
            "Myopia",
            2
        ));
        patient_data.Tail()->visit_history.InsertTail(Visit(
            "Ligma",
            "Unspecified",
            ctimew::GetTimeTFromString("2021/10/03 12:45:11"), // change to hardcoded time
            doctor_data.Head(),
            "Adderall"
        ));

        // 5
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000005",
            "Mika",
            "Lam",
            19,
            'F',
            "018-9113268",
            "6, Lorong Wae 69/6, Bukit Gae, 25250, Kuantan",
            "",
            5
        ));

        // 6
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000006",
            "Dominic",
            "Toretto",
            40,
            'M',
            "012-9999999",
            "99, Jalan Kampung Cepat, Taman Mat Rempit, 42000, Selangor",
            "",
            5
        ));
        patient_data.Tail()->visit_history.InsertTail(Visit(
            "Dizziness",
            "Unspecified",
            ctimew::GetTimeTFromString("2021/09/28 15:03:58"), // change to hardcoded time
            doctor_data.Head(),
            "Panadol"
        ));

        // 7
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000007",
            "Lisa",
            "Toretto",
            42,
            'F',
            "012-9999998",
            "99, Jalan Kampung Cepat, Taman Mat Rempit, 42000, Selangor",
            "",
            5
        ));

        // 8
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000008",
            "Eason",
            "Toretto",
            44,
            'M',
            "012-9999997",
            "99, Jalan Kampung Cepat, Taman Mat Rempit, 42000, Selangor",
            "",
            5
        ));

        // 9
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000009",
            "Keng Yeap",
            "Chong",
            32,
            'M',
            "016-3772198",
            "10A, Jalan 3B/4, Persiaran Pog, 44100, Selangor",
            "",
            5
        ));

        // 10
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000010",
            "Hou Yin",
            "Tan",
            28,
            'F',
            "016-7788453",
            "12, Jalan Kimi 7, Taman Penzine, 44100, Selangor",
            "",
            5
        ));

        // 11
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000011",
            "Tzen Fung",
            "Lim",
            42,
            'M',
            "017-7107828",
            "222, Jalan Rohulk, Taman Aliran Berakhir, 51000, Kuala Lumpur",
            "",
            5
        ));

        // 12
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000012",
            "Take",
            "Tanaka",
            14,
            'F',
            "012-9927314",
            "10575, Jalan Dalam Luar, Taman Sys, 43000, Selangor",
            "",
            5
        ));

        // 13
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000013",
            "Will",
            "Stetson",
            23,
            'M',
            "017-2772772",
            "727, Jalan Zenith Biru, Taman Strim Keterlaluan, 42000, Selangor",
            "",
            5
        ));

        // 14
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000014",
            "Jessica",
            "Simpson",
            41,
            'F',
            "019-3442106",
            "10, Jalan Angstrom, Bukit Pasir Hitam, 53000, Kuala Lumpur",
            "",
            5
        ));

        // 15
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000015",
            "Taylor",
            "Swift",
            22,
            'F',
            "016-2223333",
            "101-2C, Jalan 1/4, Taman Setia, Sentul 52000, Kuala Lumpur",
            "",
            5
        ));

        // 16
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000016",
            "Nubia",
            "Wayra",
            21,
            'F',
            "012-3334447",
            "77, Jalan 7, Taman Perindustrian Desa, 51000, Kuala Lumpur",
            "Blind",
            4
        ));

        // 17
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000017",
            "Katy",
            "Snoddon",
            41,
            'F',
            "012-0551321",
            "Perbadanan Niaga Felda, Jln Patin Felda, Sungai Retang, 27000, Jerantut, Pahang",
            "Deaf",
            4
        ));

        // 18
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000018",
            "Colleen",
            "Winsley",
            76,
            'M',
            "014-4312505",
            "No. 1, Jalan Kemajuan, Off Jalan Tampoi,81200 Johor Bahru",
            "",
            5
        ));

        // 19
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000019",
            "Helena",
            "Bagguley",
            48,
            'F',
            "014-7641570",
            "No. 260, Lbh Pantai, 10300, Pulau Pinang",
            "Crippled",
            2
        ));

        // 20
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000020",
            "Larry",
            "Gemnett",
            24,
            'M',
            "014-7042904",
            "31St Floor Block B, Centre Point, Jln Haji Abdul Rahman, 25000, Kuantan, Pahang",
            "Paralyzed",
            1
        ));

        // 21
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000021",
            "Patricia",
            "Savatier",
            37,
            'F',
            "015-3233371",
            "No 17,Taman Bukit Kuchai, Batu 8 Jalan Puchong ,47100, Selangor",
            "",
            5
        ));

        // 22
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000022",
            "Isidora",
            "Duncklee",
            29,
            'M',
            "014-6589633",
            "66, Jln Utara Batu 3, Hock Seng Light Industry, 90000, Sandakan, Sabah",
            "",
            5
        ));

        // 23
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000023",
            "Tabor",
            "Houndesome",
            25,
            'M',
            "017-2437963",
            "2251, Jln Balakong, Kampung Baru Balakong, 43300, Seri Kembangan, Selangor",
            "ALS",
            3
        ));

        // 24
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000024",
            "Dwight",
            "Karlicek",
            87,
            'M',
            "011-15713223",
            "76, Jln 2A/76A, Seksyen 1 Wangsa Maju, 53300, Wilayah Persekutuan, Kuala Lumpur",
            "",
            5
        ));

        // 25
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000025",
            "Perren",
            "Childes",
            66,
            'F',
            "016-2962393",
            "15, Jalan PJS 11/15, Bandar Sunway, 46150, Selangor",
            "",
            5
        ));

        // 26
        patient_data.InsertTail(std::make_shared<Patient>(
            "P000026",
            "Orelie",
            "Risso",
            71,
            'F',
            "011-42246777",
            "Lot 3 & 4, Lengkok Rishah Dua, Kawasan Perindustrian Silibin, 30100, Ipoh",
            "",
            5
        ));

        for(int i = 0; i < patient_data.Size(); i++)
        {
            Patient copy = *(patient_data.At(i));
            time_t time_temp = (ctimew::Time() + (i * rand() % 10000));
            waiting_data.InsertTail(std::make_shared<Waiting>(
                copy.id,
                copy.first_name,
                copy.last_name,
                copy.priority,
                time_temp
            ));

        }
    }
} // namespace pms