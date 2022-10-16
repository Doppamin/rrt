void send_all_acceptable_packages(town *source, int source_office_index, town *target, int target_office_index)
{
    int n = 0;
    for (int i = 0; i < source->offices[source_office_index].packages_count; i++)
        if (source->offices[source_office_index].packages[i].weight >= target->offices[target_office_index].min_weight &&
            source->offices[source_office_index].packages[i].weight <= target->offices[target_office_index].max_weight)
            ++n;
    package *newPackages = malloc(sizeof(package) * (n + target->offices[target_office_index].packages_count));
    package *oldPackages = malloc(sizeof(package) * (source->offices[source_office_index].packages_count - n));
    for (int i = 0; i < target->offices[target_office_index].packages_count; i++)
        newPackages[i] = target->offices[target_office_index].packages[i];
    n = target->offices[target_office_index].packages_count;
    int m = 0;
    for (int i = 0; i < source->offices[source_office_index].packages_count; i++)
        if (source->offices[source_office_index].packages[i].weight >= target->offices[target_office_index].min_weight &&
            source->offices[source_office_index].packages[i].weight <= target->offices[target_office_index].max_weight)
        {
            newPackages[n] = source->offices[source_office_index].packages[i];
            ++n;
        }
        else
        {
            oldPackages[m] = source->offices[source_office_index].packages[i];
            ++m;
        }
    target->offices[target_office_index].packages_count = n;
    free(target->offices[target_office_index].packages);
    target->offices[target_office_index].packages = newPackages;
    source->offices[source_office_index].packages_count = m;
    free(source->offices[source_office_index].packages);
    source->offices[source_office_index].packages = oldPackages;
}
