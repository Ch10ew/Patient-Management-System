#include "ResourcePool.h"

#include "../Structures/List.h"
#include "../Structures/Nurse.h"
#include "../Structures/Doctor.h"
#include "../Structures/Patient.h"
#include "../Structures/CtimeWrapper.h"

#include <map>
#include <memory>
#include <string>
#include <cctype>
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
            "P0000001",
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
            "P0000002",
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
            "P0000003",
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
            "P0000004",
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
            ctimew::GetDate(ctimew::StructTM(ctimew::Time())),
            "00:00:00",
            doctor_data.Head(),
            "Adderall"
        ));

        // 5
        patient_data.InsertTail(std::make_shared<Patient>(
            "P0000005",
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
            "P0000006",
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
            "2021-01-01",
            "00:00:00",
            doctor_data.Head(),
            "Panadol"
        ));

        // 7
        patient_data.InsertTail(std::make_shared<Patient>(
            "P0000007",
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
            "P0000008",
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
            "P0000009",
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
            "P0000010",
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
            "P0000011",
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
            "P0000012",
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
            "P0000013",
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
            "P0000014",
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
            "P0000015",
            "Taylor",
            "Swift",
            22,
            'F',
            "016-2223333",
            "101-2C, Jalan 1/4, Taman Setia, Sentul 52000, Kuala Lumpur",
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